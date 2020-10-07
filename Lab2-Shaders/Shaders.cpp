//
// Created by Amado Garcia on 9/9/20.
//

#include <iostream>
#include "Shaders.h"
#include "Math.h"
#include "Texture.h"


vector<double> Shaders::planet(double &u, double &v, double &w,
                               tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                               tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                               tuple<double, double, double> &light, vector<double> color)
{
    Math math;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(normal,light)};

    double b = intensity;
    double r = intensity;
    double g = intensity;

    if(intensity > 0.0)
        return {r * color[0], g * color[1], b * color[2]};
    else
        return {0.0, 0.0, 0.0};
}




