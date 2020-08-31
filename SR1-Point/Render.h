//
// Created by Amado Garcia on 8/30/20.
//

#ifndef SR1_POINT_RENDER_H
#define SR1_POINT_RENDER_H

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

public:
    Render();
    void glClear();
    void glFinish(char *filename);
    void glClearColor(int r, int g, int b);
    void glColor(int r, int g, int b);

    void glCreateWindow(int width, int height);
    void glViewPort(int x, int y, int width, int height);
    void glVertex(int x, int y);
};

#endif //SR1_POINT_RENDER_H
