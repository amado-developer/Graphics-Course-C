#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#include "Render.h"

void test(vector<vector<int>> points, Render &r){
    vector<int> x{};
    vector<int> y{};

    for(auto point: points){
        x.push_back(point[0]);
    }

    for(auto point: points){
        y.push_back(point[1]);
    }

    int pointsLength = points.size();
    int lineCounter = 0;
    do{
        if(lineCounter < pointsLength - 1){
            r.glLine(x[lineCounter], y[lineCounter], x[lineCounter + 1], y[lineCounter + 1]);
        }else{
            r.glLine(x[lineCounter], y[lineCounter], x[0], y[0]);
        }
        ++lineCounter;
    }while(lineCounter < pointsLength);
}
int main()
{
    Render r;
    r.glCreateWindow(1920, 1080);
    r.glViewPort(800, 200, 1019, 779);
    r.glClearColor(0, 0, 0);
    r.glClear();
    r.glColor(1, 1, 0);

    r.glColor(0.5, 0.5, 1);

//    r.glVertex(413, 177);
//    r.glVertex(448, 159);
//    r.glVertex(502, 88);
//    r.glVertex(553, 53);
//    r.glVertex(535, 36);
//    r.glVertex(676, 37);
//    r.glVertex(660, 52);
//    r.glVertex(750, 145);
//    r.glVertex(761, 179);
//    r.glVertex(672, 192);
//    r.glVertex(659, 214);
//    r.glVertex(615, 214);
//    r.glVertex(632, 230);
//    r.glVertex(580, 230);
//    r.glVertex(597, 215);
//    r.glVertex(552, 214);
//    r.glVertex(517, 144);
//    r.glVertex(466, 180);
//
//
//    r.glColor(1, 0.5, 1);
//    r.glVertex(682, 175);
//    r.glVertex(708, 120);
//    r.glVertex(735, 148);
//    r.glVertex(739, 170);
//

    r.glFinish("b.bmp");


    return 0;
}