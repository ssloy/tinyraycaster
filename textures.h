#ifndef TEXTURES_H
#define TEXTURES_H

#include <vector>
#include <cstdint>

struct Texture {
    size_t img_w, img_h; // overall image dimensions
    size_t count, size;  // number of textures and size in pixels
    std::vector<uint32_t> img; // textures storage container

    Texture(const std::string filename);
    uint32_t get(const size_t i, const size_t j, const size_t idx) const; // get the pixel (i,j) from the texture idx
    std::vector<uint32_t> get_scaled_column(const size_t texture_id, const size_t tex_coord, const size_t column_height) const; // retrieve one column (tex_coord) from the texture texture_id and scale it to the destination size
};

#endif // TEXTURES_H

