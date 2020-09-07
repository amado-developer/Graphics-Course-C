//
// Created by Amado Garcia on 9/6/20.
//

#include "Math.h"
#include <math.h>

/***********************************************************************
 * All these Math operations were provided by Denn1s (Github) in class
 * *********************************************************************/

tuple<int, int, int> Math::sum(tuple<int, int, int> v0, tuple<int, int, int> v1)
{
    return make_tuple((get<0>(v0) + get<0>(v1)), (get<1>(v0) + get<1>(v1)), (get<2>(v0) + get<2>(v1)));
}
tuple<double, double, double> Math::sub(tuple<double, double, double> v0, tuple<double, double, double> v1)
{
    return make_tuple((get<0>(v0) - get<0>(v1)), (get<1>(v0) - get<1>(v1)), (get<2>(v0) - get<2>(v1)));
}
tuple<int, int, int> Math:: mult(tuple<int, int, int> v0, int k){
    return make_tuple((get<0>(v0) * k), (get<1>(v0) * k), (get<2>(v0) * k));
}
double Math:: dot(tuple<double, double, double> v0, tuple<double, double, double> v1)
{
    return get<0>(v0) * get<0>(v1) + get<1>(v0) * get<1>(v1) + get<2>(v0) * get<2>(v1);
}
double Math:: length(tuple<double, double, double> v0)
{
    return pow((pow(get<0>(v0), 2) + pow(get<1>(v0), 2) + pow(get<2>(v0), 2)), 0.5);
}
tuple<double, double, double>Math:: norm(tuple<double, double, double> v0)
{
    double v0Length = length(v0);

    if(v0Length == 0.0)
    {
        return make_tuple(0.0, 0.0, 0.0);
    }
    return make_tuple((get<0>(v0)/v0Length), (get<1>(v0)/v0Length), (get<2>(v0)/v0Length));
}
tuple<double, double, double> Math::cross(tuple<double, double, double> v1, tuple<double, double, double> v2)
{
    int v1X = get<0>(v1);
    int v1Y = get<1>(v1);
    int v1Z = get<2>(v1);

    int v2X = get<0>(v2);
    int v2Y = get<1>(v2);
    int v2Z = get<2>(v2);

    tuple<int, int, int> cross
            {
                    make_tuple
                            (
                                    v1Y * v2Z - v1Z * v2Y,
                                    v1Z * v2X - v1X * v2Z,
                                    v1X * v2Y - v1Y * v2X
                            )
            };
    return cross;
}

