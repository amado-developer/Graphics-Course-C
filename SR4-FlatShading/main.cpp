#include <iostream>
#include "Render.h"
int main() {
    Render r;
    r.glCreateWindow(800, 800);
    r.glViewPort(0, 0, 800, 800);
    r.glClearColor(0, 0, 0);
    r.glClear(false);
    r.glColor(1, 1, 1);
    r.setIsPixels(true);
    r.load("harry_potter.obj", {400, -2800, 0}, {1000, 1000, 1500});
    r.glFinish("out.bmp");
    return 0;

}
