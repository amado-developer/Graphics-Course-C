//
// Created by Amado Garcia on 9/1/20.
//

#ifndef SR3_MODELS_OBJ_H
#define SR3_MODELS_OBJ_H
#include <vector>
using namespace std;

class Obj{
private:
    vector<vector<float>> vertices{};
    vector<vector<int>> faces{};
public:
    void read();
};


#endif //SR3_MODELS_OBJ_H
