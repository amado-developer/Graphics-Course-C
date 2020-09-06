#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>

#include "Render.h"
#include "Obj.h"
int main()
{
    Render r;
    r.glCreateWindow(3072, 1920);
    r.glViewPort(0, 0, 3072, 1920);
//    r.glClearColor(1, 1, 1);
//    r.glClear(true);
    r.glClearColor(0, 0, 0);
    r.glClear(false);
    r.glColor(1, 1, 1);
    r.setIsPixels(true);
    r.load("Harry_Potter.obj", {1536, -12500}, {4000, 4000});
//  r.glVertex(1,1);
    r.glFinish("out.bmp");

    return 0;
}


