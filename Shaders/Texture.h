//
// Created by Amado Garcia on 9/9/20.
//

#ifndef SHADERS_TEXTURE_H
#define SHADERS_TEXTURE_H

#include <string>
#include <vector>
using namespace std;
class Texture
{
    private:
        char *path;
        vector<vector<vector<double>>> pixels{};
        int widht;
        int height;
    public:
        Texture(char* path);

    Texture();

    void read();
        vector<double> getColor(double tx, double ty);
};


#endif //SHADERS_TEXTURE_H
