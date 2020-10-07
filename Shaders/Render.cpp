//
// Created by Amado Garcia on 9/9/20.
//

#include "Render.h"
#include <iostream>
#include <algorithm>

#include "Obj.h"
#include "../Shaders/Texture.h"
#include <vector>
#include <cmath>
#include "Math.h";
using namespace std;

Render::Render(Texture texture) : texture(texture) {
    this->texture = texture;
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

    if(x >= 0 && y >= 0 && x < width && y < height && x < (vW + vX) && y < (vH + vY))
    {
        framebuffer[x][y][0] = pointColor[0];
        framebuffer[x][y][1] = pointColor[1];
        framebuffer[x][y][2] = pointColor[2];
    }
}
void Render::glClear(bool isAllWindow)
{
    if(!isAllWindow)
    {
        for (int i = vY; i < (vY + vH); i++)
        {
            for (int j = vX; j < (vX + vW); j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    framebuffer[j][i][k] = (unsigned char)backgroundColor[k];
                }
            }
        }

        for (int i = vY; i < (vY + vH); i++)
        {
            for (int j = vX; j < (vX + vW); j++)
            {
                zbuffer[j][i] = -INFINITY;
            }
        }
    }
    else
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    framebuffer[j][i][k] = (unsigned char)backgroundColor[k];
                }
            }
        }

        for (int i{0}; i < height; i++)
        {
            for (int j{0}; j < width; j++)
            {
                zbuffer[j][i] = -INFINITY;
            }
        }
    }
}

void Render::setActiveRender(vector<double>(*activeShader)
        (double &u, double &v, double &w,
         tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
         tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
         Texture &texture, tuple<double, double, double> &light))
{
     this->activeShader = activeShader;
}

void Render::glColor(double r, double g, double b)
{
    pointColor[2] = (unsigned char) (r * 255.0);
    pointColor[1] = (unsigned char) (g * 255.0);
    pointColor[0] = (unsigned char) (b * 255.0);
}
void Render::glClearColor(double r, double g, double b)
{
    backgroundColor[2] = (unsigned char) (r * 255.0);
    backgroundColor[1] = (unsigned char) (g * 255.0);
    backgroundColor[0] = (unsigned char) (b * 255.0);
}
void Render::glCreateWindow(int width, int height)
{
    vector<vector<vector<unsigned char>>>framebuffer(width, vector<vector<unsigned char >>(height, vector<unsigned char >(3)));
    vector<vector<double>> zbuffer(width, vector<double>(height));
    this->zbuffer=zbuffer;
    this->framebuffer = framebuffer;
    this->width = width;
    this->height = height;
}
void Render::glViewPort(int vX, int vY, int vW, int vH)
{
    this->vX = vX;
    this->vY = vY;
    this->vW = vW;
    this->vH = vH;
}
void Render::glVertex(int x, int y)
{
    int pointX = (x + 1) * (this->vW * 0.5) + this->vX;
    int pointY= (y + 1) * (this->vH * 0.5) + this->vY;
    glPoint(pointX, pointY);
}
void Render::glFinish(char *filename)
{
    FILE* imageFile = fopen(filename, "wb");

    vector<unsigned char> file = fileHeader();
    for(auto f: file)
    {
        fwrite(&f, 1, 1, imageFile);
    }

    vector<unsigned char> header = infoHeader();
    for(auto h: header)
    {
        fwrite(&h, 1, 1, imageFile);
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                fwrite(&framebuffer[j][i][k], 1, 1, imageFile);
            }
        }
    }
    fclose(imageFile);
}
// This Bresehnham's algorithm implementation was taken from class's code, adapted  and modified a little bit to use it with viewport.
void Render::glLine(int &x1, int &y1, int &x2, int &y2)
{
    if(!isPixels)
    {
        x1 = glAdaptToViewportXCoordinates(x1);
        x2 = glAdaptToViewportXCoordinates(x2);
        y1 = glAdaptToViewportYCoordinates(y1);
        y2 = glAdaptToViewportYCoordinates(y2);
    }

    else
    {
        x1 = x1 + vX;
        x2 = x2 + vX;
        y1 = y1 + vY;
        y2 = y2 + vY;
    }

    int dy = abs(y2 - y1);
    int dx = abs(x2 - x1);

    bool steep = dy > dx;

    if(steep)
    {
        swap(x1, y1);
        swap(x2, y2);
        dy = abs(y2 - y1);
        dx = abs(x2 - x1);
    }

    if(x1 > x2)
    {
        swap(x1, x2);
        swap(y1, y2);
    }

    int offset = 0;
    int threshold = 1;
    int y = y1;

    for(auto x{x1}; x <= x2; ++x)
    {
        if(steep)
        {
            glPoint(y, x);
        }
        else
        {
            glPoint(x, y);
        }
        offset += dy * 2;

        if(offset >= threshold)
        {
            y += y1 < y2 ? 1 : - 1;
            threshold += 2 * dx;
        }
    }
}
//Parameters: A, B, C
tuple<double, double, double> Render::barycentric(tuple<double, double, double> A, tuple<double, double, double> B, tuple<double, double, double> C, tuple<double, double> P)
{
    tuple<double, double, double> c = math.cross(make_tuple(get<0>(B) - get<0>(A), get<0>(C) - get<0>(A),get<0>(A) - get<0>(P)),
                                                 (make_tuple(get<1>(B) - get<1>(A), get<1>(C) - get<1>(A),get<1>(A) - get<1>(P))));

    double cX = get<0>(c);
    double cY = get<1>(c);
    double cZ = get<2>(c);

    if(abs(cZ) < 1)
    {
        return (make_tuple(-1, -1, -1));
    }

    double u = cX / cZ;
    double v = cY / cZ;
    double w = 1 - ((cX + cY) / cZ);

    return make_tuple(w, u, v);
}
vector<int> Render::bbox(int quantity, ...)
{
    va_list args;
    va_start(args, quantity);
    vector<int> xs{};
    vector<int> ys{};
    for(auto i {0}; i < (quantity/2); ++i)
    {
        int xValue = va_arg(args, int);
        xs.push_back(abs(xValue));

        int yValue = va_arg(args, int);
        ys.push_back(abs(yValue));
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int xMin = xs[0];
    int yMin = ys[0];
    int xMax = xs[xs.size() - 1];
    int yMax = ys[ys.size() - 1];

    vector<int> bbox{xMin, yMin, xMax, yMax};

    return bbox;
}
//Paremeters: A, B, C, Color

void Render::glTriangle(tuple<int, int, int> A, tuple<int, int, int> B, tuple<int, int, int> C,
                        tuple<double, double> tA, tuple<double, double> tB, tuple<double, double> tC,
                        tuple<double, double, double> nA, tuple<double, double, double> nB,
                        tuple<double, double, double> nC
                        )
{
    vector<int> bbox = this->bbox(6, get<0>(A),get<1>(A),  get<0>(B), get<1>(B), get<0>(C), get<1>(C));
    int xMin = bbox.at(0);
    int yMin = bbox.at(1);
    int xMax = bbox.at(2);
    int yMax = bbox.at(3);

    for(auto x{xMin}; x <= xMax; ++x)
    {
        for(auto y{yMin}; y <= yMax; ++y)
        {
            if (x >= width or x < 0 or y >= height or y < 0)
            {
                continue;
            }

            tuple<double, double> P{make_tuple(x,y)};
            tuple<double, double, double> barycentric  = this->barycentric(A, B, C, P);

            double u = get<0>(barycentric);
            double v = get<1>(barycentric);
            double w = get<2>(barycentric);

            if(w < 0 || v < 0 || u < 0)
            {
                continue;
            }

            double z{get<2>(A)   * u + get<2>(B)  * v + get<2>(C) * w};

            vector<double> color = this->activeShader(u, v, w, tA, tB, tC, nA, nB, nC,this->texture, this->light);
            if( x < width && y < height && z > zbuffer[x][y])
            {
                this->glColor(color.at(0), color.at(1), color.at(2));
                glPoint(x, y);
                zbuffer[x][y] = z;
            }

        }
    }
}
void Render::load(string filename, vector<double> translate, vector<double> scale)
{
    Obj o(filename);
    o.read();

    vector<vector<double>> textureVertexes = o.getTextureVertexes();
    vector<vector<double>> vertices = o.getVertices();
    vector<vector<double>> normalVertexes = o.getNormalVertexes();
    vector<tuple<vector<int>, vector<int>, vector<int>>> faces = o.getFaces();

    for(auto face : faces)
    {

        int vcount = get<0>(face).size();
        vector<tuple<double, double, double>> vertex{};
        vector<tuple<double, double>> textureVertex{};
        vector<tuple<double, double, double>> normalVertex{};

        for(auto j{0}; j < vcount; ++j)
        {
            auto initialVertex1 =  get<0>(face).at(j) - 1;
            vector<double> vertex1 = vertices[initialVertex1];
//            double x1 = round((vertex1[0] * scale[0]) + translate[0]);
//            double y1 = round((vertex1[1] * scale[1]) + translate[1]);
//            double z1 = round((vertex1[2] * scale[2]) + translate[2]);
            vertex.push_back(make_tuple(vertex1.at(0), vertex1.at(1), vertex1.at(2)));

            auto initialVertex2 = get<1>(face).at(j) - 1;
            vector<double> vertex2 = textureVertexes[initialVertex2];
            textureVertex.push_back(make_tuple(vertex2.at(0), vertex2.at(1)));

            auto initialVertex3 = get<2>(face).at(j) - 1;
            vector<double> vertex3 = normalVertexes[initialVertex3];
            normalVertex.push_back(make_tuple(vertex3.at(0), vertex3.at(1), vertex3.at(2)));

        }
        if(vcount == 3)
        {
            tuple<double, double, double> A{vertex.at(0)};
            tuple<double, double, double> B{vertex.at(1)};
            tuple<double, double, double> C{vertex.at(2)};

            A = transform(A, translate, scale);
            B = transform(B, translate, scale);
            C = transform(C, translate, scale);

            tuple<double, double> tA{textureVertex.at(0)};
            tuple<double, double> tB{textureVertex.at(1)};
            tuple<double, double> tC{textureVertex.at(2)};

            tuple<double, double, double> nA{normalVertex.at(0)};
            tuple<double, double, double> nB{normalVertex.at(1)};
            tuple<double, double, double> nC{normalVertex.at(2)};


            tuple<double, double, double> normal {math.cross(math.sub(B, A), math.sub(C,A))};
            double intensity{math.dot(math.norm(normal),math.norm(light))};

            if(intensity < 0)
            {
                continue;
            }

            glTriangle(A, B, C, tA, tB, tC, nA, nB, nC);
        }
        else if(vcount == 4)
        {
            tuple<double, double, double> A{vertex.at(0)};
            tuple<double, double, double> B{vertex.at(1)};
            tuple<double, double, double> C{vertex.at(2)};
            tuple<double, double, double> D{vertex.at(3)};

            A = transform(A, translate, scale);
            B = transform(B, translate, scale);
            C = transform(C, translate, scale);
            D = transform(D, translate, scale);

            tuple<double, double> tA{textureVertex.at(0)};
            tuple<double, double> tB{textureVertex.at(1)};
            tuple<double, double> tC{textureVertex.at(2)};
            tuple<double, double> tD{textureVertex.at(3)};

            tuple<double, double, double> nA{normalVertex.at(0)};
            tuple<double, double, double> nB{normalVertex.at(1)};
            tuple<double, double, double> nC{normalVertex.at(2)};
            tuple<double, double, double> nD{normalVertex.at(3)};

            tuple<double, double, double> normal {math.cross(math.sub(B, A), math.sub(C,A))};
            double intensity{math.dot(math.norm(normal),math.norm(light))};

            if(intensity < 0)
            {
                continue;
            }
            glTriangle(A, B, C, tA, tB, tC, nA, nB, nC);
            glTriangle(A, C, D, tA, tC, tD, nA, nC, nD);
        }
    }
}
tuple<double, double, double> Render::transform(tuple<double, double, double> vertex, vector<double> translate, vector<double> scale)
{
    return tuple<double, double, double>
    {
        (round(get<0>(vertex) * scale.at(0) + translate.at(0))),
        (round(get<1>(vertex) * scale.at(1) + translate.at(1))),
        (round(get<2>(vertex) * scale.at(2) + translate.at(2)))
    };
}
void Render::setIsPixels(bool isPixels)
{
    this->isPixels = isPixels;
}
inline int Render:: glAdaptToViewportXCoordinates(int x)
{
    return (x + 1) * (this->vW * 0.5) + this->vX;
}
inline int Render:: glAdaptToViewportYCoordinates(int y)
{
    return (y + 1) * (this->vH * 0.5) + this->vY;
}
inline void Render:: swap(int &v1, int &v2){
    int tempV1 = v1;
    v1 = v2;
    v2 = tempV1;
}
void Render::setLight( tuple<double, double, double> light)
{
    this->light = light;
}
tuple<double, double, double> Render::getLight()
{
    return this->light;
}
Texture Render::getTexture()
{
    return this->texture;
}
