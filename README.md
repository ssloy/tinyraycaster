# Project based learning: build your own 3D shooter in a weekend

**Check [the wiki](https://github.com/ssloy/tinyraycaster/wiki) for the detailed description of what is under the hood. Screw the source code, read the wiki.**

If you are interested by this project, you might want to [check my other tiny* repositories](https://github.com/ssloy), they were fun for me to make, I hope it will fun for you to read.

***

This video shows what lies in this repository:
[![TinyRayCaster](https://raw.githubusercontent.com/ssloy/tinyraycaster/master/doc/017.png)](https://youtu.be/zPIVTqVilCM)

At the time I write this text, the repository contains mere 486 lines of code:

```sh
haqreu@daffodil:~/tinyraycaster$ cat *.cpp *.h | wc -l
486
```

# Few things tinyraycaster is NOT:
* it is NOT a game, it is a mere stub;
* it is NOT even a 3d engine;
* it is NOT a place for design pattern lectures;
* it is NOT a competitor for id Software products. People, please, I am not John Carmack and neither my students are. Focus on the word "initiation".

# Few things tinyraycaster IS:
* it IS fun;
* it IS a blank you can start from;
* it IS created in one day, check the commit history. I broke my leg, so I wrote some code instead of walking!
* it IS a project you can participate to, pull requests are welcome, and anyone can edit the wiki;
* it IS full of bugs. Bugreports are welcome!

As an example, [here are the sources](https://github.com/stephane-hulot/thanksgiving-party) for the game made by my students Salih Nascimento and Stephane Hulot, also check the following youtube video for a preview:

[![Thanksgiving party](https://img.youtube.com/vi/Ekomnk1eNFU/0.jpg)](https://www.youtube.com/watch?v=Ekomnk1eNFU)

## Compilation
```sh
sudo apt-get install libsdl2-dev
git clone https://github.com/ssloy/tinyraycaster.git
cd tinyraycaster
mkdir build
cd build
cmake ..
make
```

You can open the project in Gitpod, a free online dev evironment for GitHub:

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/ssloy/tinyraycaster/tree/ea577d67088656918a85911448b9539421a8f3e1)


On open, the editor will compile & run the program as well as open the resulting image in the editor's preview.
Just change the code in the editor and rerun the script (use the terminal's history) to see updated images.

Note that since the project in its current state is linked with the SDL2 library, Gitpod link leads to a last commit before SDL linkage.
