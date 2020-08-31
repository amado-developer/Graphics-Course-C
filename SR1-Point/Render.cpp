//
// Created by Amado Garcia on 8/30/20.
//

#include "Render.h"
#include <vector>
using namespace std;

Render::Render(int width, int height, string *filename)
{
    this -> width = width;
    this -> height = height;
    this->filename = filename;
    this->frameBuffer = NULL;
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

void Render::glClear() {
    frameBuffer = (unsigned char *)malloc(3*width*height);
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            for (int k = 0; k < 3; k++){
                *(frameBuffer + i*width*3 + j*3 + k) = (unsigned char)current_color[k];
            }
        }
    }
}
void Render::glClearColor(int r, int g, int b){
    this->current_color[2] = (unsigned char) r;
    this->current_color[1] = (unsigned char) g;
    this->current_color[0] = (unsigned char) b;

};
void Render::glFinish(){
    vector<unsigned char> file = fileHeader();
    vector<unsigned char> header = infoHeader();

    FILE* imageFile = fopen(reinterpret_cast<const char *>(filename), "wb");

    for(auto f: file){
        fwrite(&f, 1, 1, imageFile);
    }

    for(auto h: header){
        fwrite(&h, 1, 1, imageFile);
    }

    //adapted from https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
    for(int i=0; i<height; i++)
    {
        fwrite(frameBuffer+(width*(height-i-1)*3),3,width,imageFile);

    }
    fclose(imageFile);
}

