#include <iostream>
#include <fstream>

using namespace std;
#include "Render.h"
int main()
{
    Render render(3072, 1920, (string *) "hahahaha.bmp");
    render.glClearColor(0, 255, 0);
    render.glClear();
    render.glFinish();
    return 0;
}
