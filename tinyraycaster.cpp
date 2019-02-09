#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <cassert>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

uint32_t pack_color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a=255) {
    return (a<<24) + (b<<16) + (g<<8) + r;
}

void unpack_color(const uint32_t &color, uint8_t &r, uint8_t &g, uint8_t &b, uint8_t &a) {
    r = (color >>  0) & 255;
    g = (color >>  8) & 255;
    b = (color >> 16) & 255;
    a = (color >> 24) & 255;
}

void drop_ppm_image(const std::string filename, const std::vector<uint32_t> &image, const size_t w, const size_t h) {
    assert(image.size() == w*h);
    std::ofstream ofs(filename);
    ofs << "P6\n" << w << " " << h << "\n255\n";
    for (size_t i = 0; i < h*w; ++i) {
        uint8_t r, g, b, a;
        unpack_color(image[i], r, g, b, a);
        ofs << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
    }
    ofs.close();
}

void draw_rectangle(std::vector<uint32_t> &img, const size_t img_w, const size_t img_h, const size_t x, const size_t y, const size_t w, const size_t h, const uint32_t color) {
    assert(img.size()==img_w*img_h);
    for (size_t i=0; i<w; i++) {
        for (size_t j=0; j<h; j++) {
            size_t cx = x+i;
            size_t cy = y+j;
            if (cx>=img_w || cy>=img_h) continue; // no need to check for negative values (unsigned variables)
            img[cx + cy*img_w] = color;
        }
    }
}

bool load_texture(const std::string filename, std::vector<uint32_t> &texture, size_t &text_size, size_t &text_cnt) {
    int nchannels = -1, w, h;
    unsigned char *pixmap = stbi_load(filename.c_str(), &w, &h, &nchannels, 0);
    if (!pixmap) {
        std::cerr << "Error: can not load the textures" << std::endl;
        return false;
    }

    if (4!=nchannels) {
        std::cerr << "Error: the texture must be a 32 bit image" << std::endl;
        stbi_image_free(pixmap);
        return false;
    }

    text_cnt = w/h;
    text_size = w/text_cnt;
    if (w!=h*int(text_cnt)) {
        std::cerr << "Error: the texture file must contain N square textures packed horizontally" << std::endl;
        stbi_image_free(pixmap);
        return false;
    }

    texture = std::vector<uint32_t>(w*h);
    for (int j=0; j<h; j++) {
        for (int i=0; i<w; i++) {
            uint8_t r = pixmap[(i+j*w)*4+0];
            uint8_t g = pixmap[(i+j*w)*4+1];
            uint8_t b = pixmap[(i+j*w)*4+2];
            uint8_t a = pixmap[(i+j*w)*4+3];
            texture[i+j*w] = pack_color(r, g, b, a);
        }
    }
    stbi_image_free(pixmap);
    return true;
}


int main() {
    const size_t win_w = 1024; // image width
    const size_t win_h = 512;  // image height
    std::vector<uint32_t> framebuffer(win_w*win_h, pack_color(255, 255, 255)); // the image itself, initialized to white

    const size_t map_w = 16; // map width
    const size_t map_h = 16; // map height
    const char map[] = "0000222222220000"\
                       "1              0"\
                       "1      11111   0"\
                       "1     0        0"\
                       "0     0  1110000"\
                       "0     3        0"\
                       "0   10000      0"\
                       "0   0   11100  0"\
                       "0   0   0      0"\
                       "0   0   1  00000"\
                       "0       1      0"\
                       "2       1      0"\
                       "0       0      0"\
                       "0 0000000      0"\
                       "0              0"\
                       "0002222222200000"; // our game map
    assert(sizeof(map) == map_w*map_h+1); // +1 for the null terminated string
    float player_x = 3.456; // player x position
    float player_y = 2.345; // player y position
    float player_a = 1.523; // player view direction
    const float fov = M_PI/3.; // field of view

    const size_t ncolors = 10;
    std::vector<uint32_t> colors(ncolors);
    for (size_t i=0; i<ncolors; i++) {
        colors[i] = pack_color(rand()%255, rand()%255, rand()%255);
    }

    std::vector<uint32_t> walltext; // textures for the walls
    size_t walltext_size;  // texture dimensions (it is a square)
    size_t walltext_cnt;   // number of different textures in the image
    if (!load_texture("../walltext.png", walltext, walltext_size, walltext_cnt)) {
        std::cerr << "Failed to load wall textures" << std::endl;
        return -1;
    }

    const size_t rect_w = win_w/(map_w*2);
    const size_t rect_h = win_h/map_h;
    for (size_t j=0; j<map_h; j++) { // draw the map
        for (size_t i=0; i<map_w; i++) {
            if (map[i+j*map_w]==' ') continue; // skip empty spaces
            size_t rect_x = i*rect_w;
            size_t rect_y = j*rect_h;
            size_t icolor = map[i+j*map_w] - '0';
            assert(icolor<ncolors);
            draw_rectangle(framebuffer, win_w, win_h, rect_x, rect_y, rect_w, rect_h, colors[icolor]);
        }
    }

    for (size_t i=0; i<win_w/2; i++) { // draw the visibility cone AND the "3D" view
        float angle = player_a-fov/2 + fov*i/float(win_w/2);
        for (float t=0; t<20; t+=.01) {
            float cx = player_x + t*cos(angle);
            float cy = player_y + t*sin(angle);

            size_t pix_x = cx*rect_w;
            size_t pix_y = cy*rect_h;
            framebuffer[pix_x + pix_y*win_w] = pack_color(160, 160, 160); // this draws the visibility cone

            if (map[int(cx)+int(cy)*map_w]!=' ') { // our ray touches a wall, so draw the vertical column to create an illusion of 3D
                size_t icolor = map[int(cx)+int(cy)*map_w] - '0';
                assert(icolor<ncolors);
                size_t column_height = win_h/(t*cos(angle-player_a));
                draw_rectangle(framebuffer, win_w, win_h, win_w/2+i, win_h/2-column_height/2, 1, column_height, colors[icolor]);
                break;
            }
        }
    }

    const size_t texid = 4; // draw the 4th texture on the screen
    for (size_t i=0; i<walltext_size; i++) {
        for (size_t j=0; j<walltext_size; j++) {
            framebuffer[i+j*win_w] = walltext[i + texid*walltext_size + j*walltext_size*walltext_cnt];
        }
    }

    drop_ppm_image("./out.ppm", framebuffer, win_w, win_h);

    return 0;
}

