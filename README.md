# VNyl

(It's pronounced Vinyl)

VNyl is a C++ Visual Novel making framework!

## Installation 

Clone this repository. Then clone the raylib repository into `libs/raylib`

```bash
# Start in project root
$ cd libs
$ git clone https://github.com/raysan5/raylib.git
```

I recommend changing the `CMakeLists.txt` file so that it can use your project name for the executable:

```bash
# Change
project(VNyl C CXX)

# To
project(<Your_Project_Name> C CXX)
```

## Build

Now build the project from the root directory:

```bash
# Project root
$ cmake --build ./build --config Debug --target all -j 22 --
```

If there are build errors, this is likely due to missing dependencies. Look for any missing packages such as `libxinerama-dev`, `libxcursor-dev`, `libxi-dev`, etc. You will need to install them using your systems package manager. For example:

```bash
$ sudo apt install libxi-dev
```

## Recommended

When using VSCode install the `C/C++ Extension Pack`. CMake will try to configure itself into the project, and may need to be reloaded a few times.

## TODO

1. ~~Draw/hide characters. Add to list. Have predefined locations. Fade in/ out~~
2. ~~Set background image. Preload all of them. Add textures to dictionaries and select one. Fade in/out~~
3. ~~Set background music. Preload all of them. Add audio to dictionaries and select one to play on loop~~
4. Play sound effects. Preload all of them. Halt execution until finished?
5. ~~Code block. Pass in a generic lambda to execute~~
6. ~~While loop. Repeat Action List until condition is false~~
7. ~~Show text. Reveal text character by character. Display character name. Click to skip, click to continue~~
8. ~~Show menu options. Show a list of centered boxes in a vertical list layout. Pass in int pointer variable, return index of chosen option~~
9. Clear screen. Remove all text, characters, and background. Draw a black rectangle overlay that fades everything, then hide.
10. ~~Change render to scale with letterboxing. See this for [details](https://www.raylib.com/examples/core/loader.html?name=core_window_letterbox)~~