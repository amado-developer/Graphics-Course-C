//
// Created by Amado Garcia on 9/6/20.
//

#ifndef TEXTURES_TEXTURE_H
#define TEXTURES_TEXTURE_H
#include <string>
#include <vector>
using namespace std;

class Texture{
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


#endif //TEXTURES_TEXTURE_H
