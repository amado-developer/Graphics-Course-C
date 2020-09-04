//
// Created by Amado Garcia on 9/1/20.
//

#ifndef SR3_MODELS_RENDER_H
#define SR3_MODELS_RENDER_H


#include <vector>
#include <string>
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
    std::vector<unsigned char> fileHeader();
    std::vector<unsigned char> infoHeader();
    vector<vector<vector<unsigned char>>> framebuffer;
    void glPoint(int x, int y);
    inline int glAdaptToViewportXCoordinates(int x);
    inline int glAdaptToViewportYCoordinates(int y);
    inline void swap(int &x, int &y);

public:
    Render();
    void glClear();
    void glFinish(char *filename);
    void glClearColor(int r, int g, int b);
    void glColor(int r, int g, int b);
    void glCreateWindow(int width, int height);
    void glViewPort(int x, int y, int width, int height);
    void glVertex(int x, int y);
    void glLine(int &x1, int &y1, int &x2, int &y2);
    void load(string filename, vector<double> translate, vector<double> scale);
    void setIsPixels(bool isPixels);
};


#endif //SR3_MODELS_RENDER_H
