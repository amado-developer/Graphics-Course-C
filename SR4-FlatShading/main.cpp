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
    r.load("Sphere.obj", {400, 400, 0}, {100, 100, 100});
    r.glFinish("out.bmp");
    return 0;

}
