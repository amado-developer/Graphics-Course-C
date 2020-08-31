#include <iostream>
#include <fstream>

using namespace std;
#include "Render.h"
int main()
{
    Render render;
    render.glCreateWindow(800, 600);
    render.glViewPort(350, 250, 50, 50);
    render.glClearColor(0, 0, 1);
    render.glClear();
    render.glColor(1,0,0);
    render.glVertex(-1,-1);
    render.glVertex(-1, 1);
    render.glVertex(0,0);
    render.glVertex(1,-1);
    render.glVertex(1, 1);
    render.glFinish("lol.bmp");

    return 0;
}
