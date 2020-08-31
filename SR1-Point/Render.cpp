//
// Created by Amado Garcia on 8/30/20.
//

#include "Render.h"
#include <vector>
using namespace std;

Render::Render(){
}
vector<unsigned char> Render::fileHeader()
{
    int fileSize = 14 + 40 + width * height * 3;
    vector<unsigned char> fileHeader
    {
        'B', 'M',
        (unsigned char)(fileSize), 0, 0 , 0,
        0, 0, 0, 0,
        54, 0, 0, 0
    };
    return fileHeader;
}
vector<unsigned char> Render::infoHeader()
{
    int imageSize = this->width * this->height * 3;
    vector<unsigned char> infoHeader
    {
        40,0,0,0,
        (unsigned char)(width),(unsigned char)(width >> 8),(unsigned char)(width >> 16),(unsigned char)(width >> 24),
        (unsigned char)(height),(unsigned char)(height >> 8),(unsigned char)(height >> 16),(unsigned char)(height >> 24),
        1,0,
        24,0,0,0,
        0,0,
        (unsigned char)(imageSize),0,0,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0
    };

    return infoHeader;
}
void Render::glPoint(int x, int y) {
    framebuffer[x][y][0] = pointColor[0];
    framebuffer[x][y][1] = pointColor[1];
    framebuffer[x][y][2] = pointColor[2];
}
void Render::glClear() {
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            for (int k = 0; k < 3; k++){
               framebuffer[j][i][k] = (unsigned char)backgroundColor[k];
            }
        }
    }
}
void Render::glColor(int r, int g, int b){
    pointColor[2] = (unsigned char) (r * 255);
    pointColor[1] = (unsigned char) (g * 255);
    pointColor[0] = (unsigned char) (b * 255);
}
void Render::glClearColor(int r, int g, int b){
    backgroundColor[2] = (unsigned char) (r * 255);
    backgroundColor[1] = (unsigned char) (g * 255);
    backgroundColor[0] = (unsigned char) (b * 255);

}
void Render::glCreateWindow(int width, int height){
    vector<vector<vector<unsigned char>>>framebuffer(width, vector<vector<unsigned char >>(height, vector<unsigned char >(3)));
    this->framebuffer = framebuffer;
    this->width = width;
    this->height = height;
}
void Render::glViewPort(int vX, int vY, int vW, int vH){
    this->vX = vX;
    this->vY = vY;
    this->vW = vW;
    this->vH = vH;
}
void Render::glVertex(int x, int y){
    int pointX = (x + 1) * (this->vW * 0.5) + this->vX;
    int pointY= (y + 1) * (this->vH * 0.5) + this->vY;
    glPoint(pointX, pointY);
}
void Render::glFinish(char *filename){
    FILE* imageFile = fopen(filename, "wb");

    vector<unsigned char> file = fileHeader();
    for(auto f: file){
        fwrite(&f, 1, 1, imageFile);
    }

    vector<unsigned char> header = infoHeader();
    for(auto h: header){
        fwrite(&h, 1, 1, imageFile);
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            for (int k = 0; k < 3; k++){
                fwrite(&framebuffer[j][i][k], 1, 1, imageFile);
            }
        }
    }
    fclose(imageFile);
}