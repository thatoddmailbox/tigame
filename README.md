# tigame
![Demo GIF](./demo.gif)

A tiny 3D game engine, still a work in progress. Uses C++, the SDL2 library, PhysicsFS, and OpenGL.

Currently, it can display a 3D scene with various objects and some simplistic lighting, load meshes for those objects from an OBJ file, and load textures for those meshes from PNG files. You can also attach components to those objects to do various things, such as look around the scene with mouse input. There's also a (very much work-in-progress) scene editor.

## Repo structure
* `cmake` - This folder contains files used for the CMake build system.
* `demo` - This folder contains the source code of a small demo.
** `demo/data` - This folder contains data files used by the game (textures, models, etc).
* `external` - This folder contains some external libraries and headers that are used by tigame.
* `glad` - This folder contains headers used by tigame to access OpenGL in a cross-platform manner.
	* The files here are automatically generated by the Glad tool. This link will take you to the page with the settings used for tigame: http://glad.dav1d.de/#profile=core&specification=gl&api=gl%3D3.3&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&language=c&loader=on
* `src` - This folder contains the source code of the tigame engine.

## Build instructions
If you have SDL2 or PhysicsFS installed in a non-standard location, set the `SDL2DIR` and `PHYSFSDIR` environment variables before running `cmake`.

Please note that these instructions have been only tested on Linux. They should probably work on macOS, and potentially Windows with some modifications?

* Install CMake
* Get Bullet physics engine (tested with [version 3.08](https://github.com/bulletphysics/bullet3/releases/tag/3.08)), follow build instructions for your operating system.
* Install libpng and development headers (on most Linux distros, this will already be included)
* Install SDL2 and development headers
* Install [PhysicsFS](https://www.icculus.org/physfs/)
* `mkdir build && cd build`
* `cmake ..`
* `make`