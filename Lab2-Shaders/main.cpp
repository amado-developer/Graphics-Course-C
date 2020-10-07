#include <iostream>
#include "Render.h"

#include "Shaders.h"
#include <vector>
#include "Math.h"

int main()
{
    Render r;
    Math math;
    r.glCreateWindow(1920, 1080);
    r.glViewPort(0, 0, 1920, 1080);
    r.glClearColor(0.1, 0.1, 0.1);
    r.glClear(false);
    r.setIsPixels(true);
    tuple<double, double, double> modelPosition(0.0,0.0,-5.0);
    r.setIsPixels(true);
    r.setLight(math.norm(make_tuple(0.0, 0.0, 1.0)));
    Shaders s;
    r.setActiveRender(&s.planet);
    r.load("Sphere.obj", {810, 540, 0.0}, {300.0, 300.0, 300.0});
    r.glFinish("out.bmp");
    return 0;
}



