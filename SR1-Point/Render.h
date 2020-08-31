//
// Created by Amado Garcia on 8/30/20.
//

#ifndef SR1_POINT_RENDER_H
#define SR1_POINT_RENDER_H

//FileHeader 14 bytes
//InfoHeader 40 bytes
//ImageData what is in the framebuffer

#include <vector>
#include <string>
using namespace std;
class Render {

private:
    unsigned char current_color[3];
    int width;
    int height;
    string *filename;
    std::vector<unsigned char> fileHeader();
    std::vector<unsigned char> infoHeader();
    vector<vector<vector<unsigned char>>> framebuffer;

public:
    Render(int width, int height, string *name);
    void glClear();
    void glFinish();
    void glClearColor(int r, int g, int b);
};


#endif //SR1_POINT_RENDER_H
