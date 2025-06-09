An image viewer for X11 display servers, powered by C++ and the [stb_image.h](https://github.com/nothings/stb) library for support with PNG, JPEG, BMP and other formats.

This is still WIP.

For now, the colors are messed up since they are forcefully piped into RGBA channels.

The stb libs are listed under public domain, and I have thus distributed them alongside the source code.

# Instructions for Compiling/Running
## Prerequisites
(For Linux systems) g++, X11 libraries (``libx11-dev`` on Debian based systems), stb_image lib (already placed in the source folder)

## Compilation and Usage
``g++ main.c -o show -lX11``<br>

``./show {image_path}``

# To-Do
Fix colors.

