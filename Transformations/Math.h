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
        vector<vector<double>> transposedMatrix(vector<vector<double>> matrix);
        vector<vector<double>> adjacencyMatrix(vector<vector<double>> matrix, int i, int j);
        double sarrus(vector<vector<double>> matrix);
        double determinant(vector<vector<double>> matrix);
        vector<vector<double>> adjacencyCalculator(vector<vector<double>> matrix);
        vector<vector<double>> inverseMatrix(vector<vector<double>> matrix);
        vector<double> vectorMatrixMult(vector<double> vectorA, vector<vector<double>> matrixB);
        vector<vector<double>> tupleToVector(tuple<double, double, double>);
};

#endif //SHADERS_MATH_H
