//
// Created by Amado Garcia on 9/9/20.
//

#include <iostream>
#include "Shaders.h"
#include "Math.h"
#include "Texture.h"


vector<double> Shaders::gourad(double &u, double &v, double &w,
                               tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                               tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                               Texture &texture, tuple<double, double, double> &light)
{
    Math math;

    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;

    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};
    if(intensity < 0)
    {
        return {0.0,0.0,0.0};
    }
    double b = 1 * intensity;
    double r = 1 * intensity;
    double g = 1 * intensity;


    auto color = texture.getColor(tX, tY);
    double b1 = b  * color[2];
    double g1 = g  * color[1];
    double r1 = r  * color[0];

    return {r1, g1, b1};
}

vector<double> Shaders::toon(double &u, double &v, double &w,
                               tuple<double, double> &tA, tuple<double, double> &tB, tuple<double, double> &tC,
                               tuple<double, double, double> &nA, tuple<double, double, double> &nB, tuple<double, double, double> &nC,
                               Texture &texture, tuple<double, double, double> &light)
{
    Math math;


    double tX = get<0>(tA) * u + get<0>(tB) * v + get<0>(tC) * w;
    double tY = get<1>(tA) * u + get<1>(tB) * v + get<1>(tC) * w;


    double nX = get<0>(nA) * u + get<0>(nB) * v + get<0>(nC) * w;
    double nY = get<1>(nA) * u + get<1>(nB) * v + get<1>(nC) * w;
    double nZ = get<2>(nA) * u + get<2>(nB) * v + get<2>(nC) * w;

    tuple<double, double, double> normal{nX, nY, nZ};
    double intensity{math.dot(math.norm(normal),math.norm(light))};

    if(intensity > 0)
    {
        if (intensity > 0.9)
        {
            intensity = 0.85;
        }
        else if(intensity > 0.7)
        {
            intensity = 0.65;
        }

        else if(intensity > 0.5)
        {
            intensity = 0.45;
        }
        else if(intensity > 0.3)
        {
            intensity = 0.25;
        }

        else if(intensity > 0.1)
        {
            intensity = 0.05;
        }
    }

    double b = 1 * intensity;
    double r = 1 * intensity;
    double g = 1 * intensity;


    auto color = texture.getColor(tX, tY);
    double b1 = b  * color[2];
    double g1 = g  * color[1];
    double r1 = r  * color[0];


    if(intensity > 0.0)
    {
        return {r1, g1, b1};
    }
    else
        return {0.0, 0.0, 0.0};
}



