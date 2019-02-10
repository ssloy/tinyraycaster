# Project based learning: build your own 3D shooter in a weekend


***

**Check [the wiki](https://github.com/ssloy/tinyraycaster/wiki) for the detailed description of what is under the hood.**

If you are interested by this project, [check my other tiny* repositories](https://github.com/ssloy), it is quite possible you will find more fun stuff there.

***

Click to see the video:
[![TinyRayCaster](https://raw.githubusercontent.com/ssloy/tinyraycaster/master/doc/017.png)](https://youtu.be/zPIVTqVilCM)

# Few things tinyraycaster is NOT:
* it is NOT a game, it is a mere stub;
* it is NOT even a 3d engine;
* it is NOT a place for design pattern lectures
* it is NOT a competitor for id Software products. People, please, I am not John Carmack and neither my students are. Focus on the word "initiation".

# Few things tinyraycaster IS:
* it IS fun
* it IS a blank you can start from
* it IS a project you can participate to, pull requests are welcome, and anyone can edit the wiki
* it IS created in one day, check the commit history. I broke my leg, so I wrote some code instead of walking!
* it IS full of bugs. Bugreports/pull requests are welcome!

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

[![Open in Gitpod](https://gitpod.io/button/open-in-gitpod.svg)](https://gitpod.io/#https://github.com/ssloy/tinyraycaster/tree/63f1a5639a0f895da1c60e3698105f740f3aa319)


On open, the editor will compile & run the program as well as open the resulting image in the editor's preview.
Just change the code in the editor and rerun the script (use the terminal's history) to see updated images.

Note that since the project in its current state is linked with the SDL2 library, Gitpod link leads to a last commit before SDL linkage.
