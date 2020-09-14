//
// Created by Amado Garcia on 9/9/20.
//

#ifndef TRANSFORMATIONS_TEXTURE_H
#define TRANSFORMATIONS_TEXTURE_H

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
        void read();
        vector<double> getColor(double tx, double ty);
};


#endif
