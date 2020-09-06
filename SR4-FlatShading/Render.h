//
// Created by Amado Garcia on 9/4/20.
//

#ifndef SR4_FLATSHADING_RENDER_H
#define SR4_FLATSHADING_RENDER_H


#include <vector>
#include <string>
#include "Math.h"
using namespace std;
class Render {

private:
    unsigned char backgroundColor[3];
    unsigned char pointColor[3];
    bool isPixels;
    int width;
    int height;
    string *filename;
    int vX;
    int vY;
    int vW;
    int vH;
    inline tuple<double, double, double> cross(tuple<double, double, double> v1, tuple<double, double, double> v2);
    vector<int> bbox(int quantity, ...);
    std::vector<unsigned char> fileHeader();
    std::vector<unsigned char> infoHeader();
    vector<vector<vector<unsigned char>>> framebuffer;
    vector<vector<double>> zbuffer;
    tuple<double, double, double> barycentric(tuple<double, double, double> A, tuple<double, double, double> B, tuple<double, double, double> C, tuple<double, double> P);
    void glPoint(int x, int y);
    inline int glAdaptToViewportXCoordinates(int x);
    inline int glAdaptToViewportYCoordinates(int y);
    inline void swap(int &x, int &y);
    Math math;

public:
    Render();

    void glClear(bool isAllWindow);
    void glFinish(char *filename);
    void glClearColor(double r, double g, double b);
    void glColor(double r, double g, double b);
    void glCreateWindow(int width, int height);
    void glViewPort(int x, int y, int width, int height);
    void glVertex(int x, int y);
    void glLine(int &x1, int &y1, int &x2, int &y2);
    void load(string filename, vector<double> translate, vector<double> scale);
    void setIsPixels(bool isPixels);
    void glTriangle(tuple<int, int, int> A, tuple<int, int, int> B, tuple<int, int, int> C);

};

#endif //SR4_FLATSHADING_RENDER_H
