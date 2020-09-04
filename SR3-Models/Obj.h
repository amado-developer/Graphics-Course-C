//
// Created by Amado Garcia on 9/1/20.
//

#ifndef SR3_MODELS_OBJ_H
#define SR3_MODELS_OBJ_H
#include <vector>
#include <string>

using namespace std;

class Obj{
private:
    vector<vector<float>> vertices{};
    vector<vector<int>> faces{};
    string filename;
public:
    Obj(string filename);
    void read();
    vector<vector<int>> getFaces();
    vector<vector<float>> getVertices();
};


#endif //SR3_MODELS_OBJ_H
