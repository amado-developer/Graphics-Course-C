//
// Created by Amado Garcia on 8/31/20.
//

#ifndef SR2_LINE_RENDER_H
#define SR2_LINE_RENDER_H

#include <vector>
#include <string>
using namespace std;
class Render {

private:
    unsigned char backgroundColor[3];
    unsigned char pointColor[3];
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
    void glLine(int x0, int x1, int y0, int y1);

};

#endif //SR2_LINE_RENDER_H