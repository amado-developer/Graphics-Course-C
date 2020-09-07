//
// Created by Amado Garcia on 9/6/20.
//

#ifndef TEXTURES_OBJ_H
#define TEXTURES_OBJ_H

#include <vector>
#include <string>

using namespace std;

class Obj{
private:
    vector<vector<double>> vertices{};
    vector<tuple<vector<int>, vector<int>>> faces{};
//    vector<vector<int>> textureFaces{};
    vector<vector<double>> textureVertexes;
    string filename;
public:
    Obj(string filename);
    void read();
    vector<tuple<vector<int>, vector<int>>> getFaces();
    vector<vector<double>> getVertices();
    vector<vector<double>> getTextureVertexes();


};
#endif //TEXTURES_OBJ_H
