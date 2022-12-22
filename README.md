# VNyl

(It's pronounced Vinyl)

VNyl is a C++ Visual Novel making framework!

## Installation / Build

Download and install [vcpkg](https://github.com/microsoft/vcpkg). Make sure it is *not* in this project's files.

After installing run:

```
$ vcpkg install sdl2
```

Also setup env variables in your `.bashrc` for `VCPKG_HOME`, and `SDL2_DIR` (this should be located in `$VCPKG_HOME/installed/x64-linux/share/sdl2`). Then run in the root of this project:

```
$ cmake -B ./build -S . "-DCMAKE_TOOLCHAIN_FILE=$VCPKG_HOME/scripts/buildsystems/vcpkg.cmake"
$ cmake --build ./build
```

## Recommended

When using VSCode install the `C/C++ Extension Pack`.
Add these lines to your `.vscode/settings.json` file:

```json
"cmake.configureSettings": {
        "CMAKE_TOOLCHAIN_FILE": "$VCPKG_HOME/scripts/buildsystems/vcpkg.cmake"
    }
```