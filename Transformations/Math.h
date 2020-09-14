//
// Created by Amado Garcia on 9/9/20.
//

#ifndef TRANSFORMATIONS_MATH_H
#define TRANSFORMATIONS_MATH_H

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
        double degreeToRadian(double degree);
        vector<vector<double>> matrixMult(vector<vector<double>> matrixA, vector<vector<double>> matrixB);
        vector<vector<double>> oneDimensionMatrixMult(vector<vector<double>> matrixA, vector<vector<double>> matrixB);
        //https://www.tutorialspoint.com/cplusplus-program-to-find-inverse-of-a-graph-matrix#:~:text=Begin%20function%20INV()%20to,%2F%20DET(matrix)%20End.

};

#endif //SHADERS_MATH_H
