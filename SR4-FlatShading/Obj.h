//
// Created by Amado Garcia on 9/4/20.
//

#ifndef SR4_FLATSHADING_OBJ_H
#define SR4_FLATSHADING_OBJ_H


#include <vector>
#include <string>

using namespace std;

class Obj{
private:
    vector<vector<double>> vertices{};
    vector<vector<int>> faces{};
    string filename;
public:
    Obj(string filename);
    void read();
    vector<vector<int>> getFaces();
    vector<vector<double>> getVertices();
};

#endif //SR4_FLATSHADING_OBJ_H
