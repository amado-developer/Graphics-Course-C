//
// Created by Amado Garcia on 9/9/20.
//

#include "Math.h"
#include <math.h>
using namespace std;
#include <vector>

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
    double v1X = get<0>(v1);
    double v1Y = get<1>(v1);
    double v1Z = get<2>(v1);

    double v2X = get<0>(v2);
    double v2Y = get<1>(v2);
    double v2Z = get<2>(v2);

    tuple<double, double, double> cross
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

/*************************************************************FUNCTIONS MADE BY ME*************************************************************************/
vector<vector<double>> Math::transposedMatrix(vector<vector<double>> matrix)
{
    vector<vector<double>> transposedMatrix;
    for (int i{0}; i < matrix.size() ; ++i)
    {
        vector<double> row;
        for (int j{0}; j < matrix.size(); ++j)
        {
            row.push_back(matrix[j][i]);
        }
        transposedMatrix.push_back(row);
    }

    return transposedMatrix;
}

vector<vector<double>> Math::adjacencyMatrix(vector<vector<double>> matrix, int i, int j)
{
    matrix.erase(matrix.begin() + i);
    for(auto i{0}; i < matrix.size(); ++i)
    {
        matrix[i].erase(matrix[i].begin() + j);
    }

    return matrix;
}

vector<vector<double>> Math::inverseMatrix(vector<vector<double>> matrix)
{
    auto adjacencyMatrix = adjacencyCalculator(matrix);
    double det = determinant(matrix);
    auto transMatrix = transposedMatrix(adjacencyMatrix);
    vector<vector<double>> inverseMatrix;
    for(auto i{0}; i < transMatrix.size(); ++i)
    {
        vector<double> row{};
        for(auto j{0}; j < transMatrix.size(); ++j )
        {
            row.push_back(transMatrix[i][j] / det);
        }
        inverseMatrix.push_back(row);
    }
    return inverseMatrix;
}

double Math::sarrus(vector<vector<double>> matrix)
{
    if(matrix.size() == 2)
    {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    return matrix[0][0] * matrix[1][1] * matrix[2][2]
           + matrix[0][1] * matrix[1][2] * matrix[2][0]
           + matrix[1][0] * matrix[2][1] * matrix[0][2]
           - matrix[0][2] * matrix[1][1] * matrix[2][0]
           - matrix[0][1] * matrix[1][0] * matrix[2][2]
           - matrix[1][2] * matrix[2][1] * matrix[0][0];
}

double Math::determinant(vector<vector<double>> matrix)
{
    if(matrix.size() < 4)
    {
        return sarrus(matrix);
    }
    double determinant{0};
    for(auto i{0}; i < matrix.size(); ++i)
    {
        if(i % 2 == 0)
        {
            determinant += matrix[i][0] * sarrus(adjacencyMatrix(matrix,i, 0));
            continue;
        }
        determinant -=  matrix[i][0] * sarrus(adjacencyMatrix(matrix,i, 0));
    }
    return determinant;
}

vector<vector<double>> Math::adjacencyCalculator(vector<vector<double>> matrix)
{
    vector<vector<double>> adjacency{};

    for(auto i{0}; i < matrix.size(); ++i)
    {
        vector<double> rowElements{};
        for (int j{0}; j < matrix.size(); ++j)
        {
            bool lol = i + j % 2 == 0;
            if((i + j) % 2 == 0)
            {
                rowElements.push_back(sarrus(adjacencyMatrix(matrix,i,j)));
            }
            else
            {
                rowElements.push_back(-sarrus(adjacencyMatrix(matrix,i,j)));
            }

        }
        adjacency.push_back({rowElements});
    }
    return adjacency;
}

vector<vector<double>> Math::matrixMult(vector<vector<double>> matrixA, vector<vector<double>> matrixB)
{
    vector<vector<double>> matrixC{};

    for (int i = 0; i < matrixA.size(); ++i)
    {
        vector<double> row{};
        for (int j = 0; j < matrixA.size(); ++j)
        {
            double positionResult{};

            for (int k = 0; k < matrixA.size() ; ++k)
            {
                positionResult += matrixA[i][k] * matrixB[k][j];
            }
            row.push_back(positionResult);
        }
        matrixC.push_back(row);
    }

    return matrixC;
}

vector<double> Math::vectorMatrixMult(vector<double> vectorA, vector<vector<double>> matrixB)
{
    vector<double> vectorC{};
    for (int i = 0; i < vectorA.size(); ++i)
    {
        double result{};
        for (int j = 0; j < vectorA.size(); ++j)
        {
            result += vectorA[j] * matrixB[i][j];
        }
        vectorC.push_back(result);
    }
    return vectorC;
}

double Math::degreeToRadian(double degree)
{
    return (degree * M_PI)/180;
}
/**********************************************************************************************************************************************************/