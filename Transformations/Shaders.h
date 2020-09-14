//
// Created by Amado Garcia on 9/9/20.
//

#ifndef TRANSFORMATIONS_SHADERS_H
#define TRANSFORMATIONS_SHADERS_H

#include "Math.h"
#include <vector>
#include <vector>
#include <random>

#include "Render.h"
#include "Texture.h"
using namespace std;

class Shaders
{
    public:
    static vector<double>
    gourad(double &u, double &v, double &w, tuple<double, double> &tA, tuple<double, double> &tB,
           tuple<double, double> &tC,
           tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
           Texture &texture, tuple<double, double, double> &light);

    static vector<double>
    toon(double &u, double &v, double &w, tuple<double, double> &tA, tuple<double, double> &tB,
           tuple<double, double> &tC,
           tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
           Texture &texture, tuple<double, double, double> &light);
};


#endif //SHADERS_SHADERS_H
