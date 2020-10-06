#include <iostream>
#include "Render.h"
int main() {
    Render r;
    r.glCreateWindow(800, 600);
    r.glViewPort(0, 0, 800, 600);
    r.glClearColor(0, 0, 0);
    r.glClear(false);

    r.setIsPixels(true);

    r.glColor(1, 1, 0);
    r.fillPolygon({165, 185, 180, 207, 233, 230, 250, 220, 205, 193},
                  {380, 360, 330, 345, 330, 360, 380, 385, 410, 383});
    r.glColor(1, 0, 0);
    r.fillPolygon({321, 288, 339, 374}, {335, 286, 251, 302});
    r.glColor(0, 0, 1);
    r.fillPolygon({377, 411, 436}, {249, 197, 249 });
    r.glColor(0.36, 0.75, 0.73);
    r.fillPolygon(
            {413,448, 502, 553, 535, 676, 660, 750, 761, 672, 659, 615, 632, 580, 597, 552,
             517, 466 },
            {177, 159, 88, 53, 36, 37, 52, 145, 179, 192, 214, 214, 230, 230, 215, 214, 144, 180});
    r.glColor(0,0,0);
    r.fillPolygon({682, 708, 735, 739},{175, 120, 148, 170});
    r.glFinish("polygon.bmp");
    return 0;
}
