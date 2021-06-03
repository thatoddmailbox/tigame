# tigame
![Demo GIF](./demo.gif)

A tiny 3D game engine, still a work in progress. Uses C++, the SDL2 library, PhysicsFS, and OpenGL.

Currently, it can display a 3D scene with various objects and some simplistic lighting, load meshes for those objects from an OBJ file, and load textures for those meshes from PNG files. You can attach components to those objects to do various things, such as look around the scene with mouse input. There's also a (very much work-in-progress) scene editor.

## Build instructions
If you have SDL2 or PhysicsFS installed in a non-standard location, set the `SDL2DIR` and `PHYSFSDIR` environment variables before running `cmake`.

Please note that these instructions have been only tested on Linux. They should probably work on macOS, and potentially Windows with some modifications?

* Install CMake
* Get Bullet physics engine (tested with [version 3.09](https://github.com/bulletphysics/bullet3/releases/tag/3.09)), follow build instructions for your operating system.
* Install libpng and development headers (on most Linux distros, this will already be included)
* Install SDL2 and development headers
* Install [PhysicsFS](https://www.icculus.org/physfs/)
* `cd` into a tigame project folder (such as `editor/` or `demo/`)
* `mkdir build && cd build`
* `cmake ..`
* `make`

## Project setup
**Note that everything is still a work in progress and this setup might break at some point in the future!**

To create a new project using tigame, first make a new folder. Then create a CMakeLists.txt file with the following contents:

```cmake
cmake_minimum_required(VERSION 3.7)

project(my-cool-game)

file(GLOB GAME_SOURCES *.cpp)
include("PATH_TO_TIGAME/CMakeLists.txt")
```

You must change `PATH_TO_TIGAME` so that the `PATH_TO_TIGAME/CMakeLists.txt` points to tigame's CMakeLists.txt file. You can also change `my-cool-game` to an identifier for your game.

Once you've done that, create a `main.cpp` file. (you can look at the demo to see what the structure of that file should be) Then, follow the "Build instructions" section (above) to compile your game.

By default, all `.cpp` files in your game's source folder will be included in the build. You can change this by modifying the `GAME_SOURCES` CMake variable in the CMakeLists.txt file.

## Concepts
The main idea is that you set up a `tigame::Game` object and then call its `Run` function, which takes over control flow. The game object has an active `tigame::Scene`, which is what is displayed to the user.

## Repo structure
* `cmake` - This folder contains files used for the CMake build system.
* `demo` - This folder contains the source code of a small demo.
	* `demo/data` - This folder contains data files used by the demo (textures, models, etc).
* `editor` - This folder contains the source code of the scene editor, which is still a work in progress.
* `external` - This folder contains some external libraries and headers that are used by tigame.
* `glad` - This folder contains headers used by tigame to access OpenGL in a cross-platform manner.
	* The files here are automatically generated by the Glad tool. This link will take you to the page with the settings used for tigame: http://glad.dav1d.de/#profile=core&specification=gl&api=gl%3D3.3&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&language=c&loader=on
* `src` - This folder contains the source code of the tigame engine.
	* `src/components` - This folder contains the source code of some built-in components, which you can use with objects in your game.