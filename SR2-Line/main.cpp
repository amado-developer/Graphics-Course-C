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



    r.glFinish("b.bmp");


    return 0;
}
