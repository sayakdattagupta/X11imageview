#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <X11/Xlib.h>
#include <iostream>

Display* dpy;
static int scr;
Window win;

int main(int argc, char** argv) 
{
    int width, height, channels;
    unsigned char* data = stbi_load(argv[1], &width, &height, &channels, 4); 

    dpy = XOpenDisplay(nullptr);
    scr = DefaultScreen(dpy);
    win = XCreateSimpleWindow(dpy,RootWindow(dpy,scr),0,0,width,height,1,BlackPixel(dpy,scr),WhitePixel(dpy,scr));

    XSelectInput(dpy,win,ExposureMask);
    XMapWindow(dpy,win);

    XImage* ximage = XCreateImage(dpy,DefaultVisual(dpy,scr),DefaultDepth(dpy,scr),ZPixmap,0,(char*)data,width,height,32,0);

    GC gc = XCreateGC(dpy,win,0,nullptr);

    XEvent ev;

    while (true) {
        XNextEvent(dpy,&ev);
        if (ev.type == Expose)
            XPutImage(dpy,win,gc,ximage,0,0,0,0,width,height);
    }

    stbi_image_free(data);
    XCloseDisplay(dpy);
    return 0;
}

