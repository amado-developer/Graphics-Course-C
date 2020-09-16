//
// Created by Amado Garcia on 9/9/20.
//

#include "Texture.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
using namespace std;
Texture::Texture(char *path)
{
    this->path = path;
    this->widht = 0;
    this->height = 0;
}
void Texture::read()
{
    int i;
    FILE* f = fopen(path, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f);


    int headerSize = *(int*)&info[10];
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    this->widht = width;
    this->height = height;
    fseek(f, headerSize, SEEK_SET);
    int size = 3 * width * height;
    vector<vector<vector<double>>>pixels(width, vector<vector<double>>(height, vector<double >(3)));
    this->pixels = pixels;
    int x{0};
    int y{0};
    for(i = 0; i < size; i += 3)
    {
        if(x == width)
        {
            x = 0;
            ++y;
            continue;
        }

        if(y == height)
        {
            break;
        }
        unsigned char data[1];
        fread(data, sizeof(unsigned char), 1, f);
        double r = data[0];
        unsigned char data2[1];
        fread(data2, sizeof(unsigned char), 1, f);
        double g = data2[0];
        unsigned char data3[1];
        fread(data3, sizeof(unsigned char), 1, f);
        double b = data3[0];

        this->pixels[y][x][0] = (b / 255.0);
        this->pixels[y][x][1] = (g / 255.0);
        this->pixels[y][x][2] = (r / 255.0);
        ++x;
    }
    fclose(f);
}
vector<double> Texture::getColor(double tx, double ty)
{
    if(tx >= 0 && tx <= 1 && ty >= 0 && ty <= 1)
    {
        int x = tx * this->widht - 1;
        int y = ty * this->height - 1;
        return this->pixels[y][x];
    }
    else
    {
        return {0};
    }
}

