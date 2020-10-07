//
// Created by Amado Garcia on 9/9/20.
//

#ifndef SHADERS_SHADERS_H
#define SHADERS_SHADERS_H

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
    static double r1;
    static double g1;
    static double b1;
    static
    vector<double>
    planet(double &u, double &v, double &w, tuple<double, double> &tA, tuple<double, double> &tB,
           tuple<double, double> &tC,
           tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
           tuple<double, double, double> &light, vector<double> color);
};


#endif //SHADERS_SHADERS_H
