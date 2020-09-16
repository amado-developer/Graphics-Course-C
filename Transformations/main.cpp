#include <iostream>
#include "Render.h"
#include "Texture.h"
#include "Shaders.h"
#include <vector>
#include "Math.h"
using namespace std;
int main()
{
    Math math;
    Texture t("model.bmp");
    t.read();
    Render r(t);
    r.glCreateWindow(800, 600);
    r.glViewPort(0, 0, 800, 600);
    r.glClearColor(0.1, 0.1, 0.1);
    r.glClear(false);
    r.setIsPixels(true);
    tuple<double, double, double> modelPosition(0.0,0.0,-5.0);
    r.createViewMatrix(make_tuple(0.0,0.0,0.0), make_tuple(0.0,0.0,0.0));
    r.createProjectionMatrix(0.1,1000.0,60.0);
    r.lookAt(modelPosition, make_tuple(2.0, 2.0, 0.0));
    r.setLight(math.norm(make_tuple(0.0, 0.0, 1.0)));
    Shaders s;
    r.setActiveRender(&s.gourad);
    r.load("model.obj", {0.0, 0.0, -5}, {2.0, 2.0, 2.0}, {0.0,0.0,0.0});
    r.glFinish("out.bmp");
    return 0;
}



