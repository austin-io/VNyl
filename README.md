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
$ cmake -B ./build
```

If there are build errors, this is likely due to missing dependencies. Look for any missing packages such as `libxinerama-dev`, `libxcursor-dev`, `libxi-dev`, etc. You will need to install them using your systems package manager. For example:

```bash
$ sudo apt install libxi-dev
```

## Recommended

When using VSCode install the `C/C++ Extension Pack`. CMake will try to configure itself into the project, and may need to be reloaded a few times.