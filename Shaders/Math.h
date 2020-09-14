//
// Created by Amado Garcia on 9/9/20.
//

#ifndef SHADERS_MATH_H
#define SHADERS_MATH_H

#include <tuple>
using namespace std;
class Math
{
    public:
        tuple<int, int, int> sum(tuple<int, int, int> v0, tuple<int, int, int> v1);
        tuple<double, double, double> sub(tuple<double, double, double> v0, tuple<double, double, double> v1);
        tuple<int, int, int> mult(tuple<int, int, int> v0, int k);
        double dot(tuple<double, double, double> v0, tuple<double, double, double> v1);
        double length(tuple<double, double, double> v0);
        tuple<double, double, double> norm(tuple<double, double, double> v0);
        tuple<double, double, double> cross(tuple<double, double, double> u, tuple<double, double, double> w);
};

#endif //SHADERS_MATH_H
