#include <iostream>
#include "Render.h"
#include "Texture.h"

int main() {
    Texture t("model.bmp");
    t.read();
    Render r(t);
    r.glCreateWindow(600, 600);
    r.glViewPort(0, 0, 600, 600);
    r.glClearColor(0, 0, 0);
    r.glClear(false);
//    r.glColor(1, 1, 1);
    r.setIsPixels(true);
    r.load("model.obj", {300, 300, 0}, {300, 300, 0});
    r.glFinish("out.bmp");
    return 0;
}