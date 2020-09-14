#include <iostream>
#include "Render.h"
#include "Texture.h"
#include "Shaders.h"
#include <vector>
#include "Math.h"

int main() {
    Math math;
    Texture t("pen.bmp");
    t.read();
    Render r(t);
    r.glCreateWindow(800, 600);
    r.glViewPort(0, 0, 800, 600);
    r.glClearColor(0.1, 0.1, 0.1);
    r.glClear(false);
    r.setIsPixels(true);
    r.setLight(math.norm(make_tuple(0.1, 0.5, 0.5)));
    Shaders s;
    r.setActiveRender(&s.toon);
    r.load("pen.obj", {400.0, 200.0, 0.0}, {300.0, 300.0, 10.0});
    r.glFinish("out.bmp");

    return 0;
}



