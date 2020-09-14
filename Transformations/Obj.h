//
// Created by Amado Garcia on 9/9/20.
//

#ifndef TRANSFORMATIONS_OBJ_H
#define TRANSFORMATIONS_OBJ_H

#include <vector>
#include <string>

using namespace std;
class Obj
{
    private:
        vector<vector<double>> vertices{};
        vector<tuple<vector<int>, vector<int>, vector<int>>> faces{};
        vector<vector<double>> textureVertexes;
        vector<vector<double>> normalVertexes;
        string filename;
    public:
        Obj(string filename);
        void read();
        vector<tuple<vector<int>, vector<int>, vector<int>>> getFaces();
        vector<vector<double>> getVertices();
        vector<vector<double>> getTextureVertexes();

    vector<vector<double>> getNormalVertexes();

};


#endif //SHADERS_OBJ_H
