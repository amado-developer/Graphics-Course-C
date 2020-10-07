#include <iostream>
#include "Render.h"
#include "Texture.h"
#include "Shaders.h"
#include <vector>
#include "Math.h"

int main() {
    Math math;
    Texture t("model.bmp");
    t.read();
    Render r(t);
    r.glCreateWindow(1920, 1080);
    r.glViewPort(0, 0, 1920, 1080);
    r.glClearColor(0.1, 0.1, 0.1);
    r.glClear(false);
    r.setIsPixels(true);
    r.setLight(math.norm(make_tuple(0.0, 0.0, 1.0)));
    Shaders s;
    r.setActiveRender(&s.gourad);
    r.load("model.obj", {810, 540, 0.0}, {300.0, 300.0, 300.0});
    r.glFinish("out.bmp");

    return 0;
}



