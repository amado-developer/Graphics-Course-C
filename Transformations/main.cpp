#include <iostream>
#include "Render.h"
#include "Texture.h"
#include "Shaders.h"
#include <vector>
#include "Math.h"

vector<vector<double>> transposedMatrix(vector<vector<double>> matrix)
{
    vector<vector<double>> transposedMatrix;
    for (int i{0}; i < matrix.size() ; ++i) {
        vector<double> row;
        for (int j{0}; j < matrix.size(); ++j) {
            row.push_back(matrix[j][i]);
        }
        transposedMatrix.push_back(row);
    }

    return transposedMatrix;
}

vector<vector<double>> adjacencyMatrix(vector<vector<double>> matrix, int i, int j)
{
    matrix.erase(matrix.begin() + i);
    for(auto i{0}; i < matrix.size(); ++i)
    {
        matrix[i].erase(matrix[i].begin() + j);
    }

    return matrix;
}

vector<vector<double>> inverseMatrix(vector<vector<double>> transposedMatrix, double det)
{
    vector<vector<double>> inverseMatrix;
    for(auto i{0}; i < transposedMatrix.size(); ++i)
    {
        vector<double> row{};
        for(auto j{0}; j < transposedMatrix.size(); ++j )
        {
            row.push_back(transposedMatrix[i][j] / det);
        }
        inverseMatrix.push_back(row);
    }
    return inverseMatrix;
}

double sarrus(vector<vector<double>> matrix)
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

double determinant(vector<vector<double>> matrix)
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

vector<vector<double>> adjacencyCalculator(vector<vector<double>> matrix)
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


int main() {
//    Math math;
//    Texture t("model.bmp");
//    t.read();
//    Render r(t);
//    r.glCreateWindow(800, 600);
//    r.glViewPort(0, 0, 800, 600);
//    r.glClearColor(0.1, 0.1, 0.1);
//    r.glClear(false);
//    r.setIsPixels(true);
//    r.setLight(math.norm(make_tuple(0.4, 0.1, 0.5)));
//    Shaders s;
//    r.setActiveRender(&s.gourad);
//    r.load("model.obj", {400.0, 300.0, 0.0}, {280.0, 280.0, 10.0});
//    r.glFinish("out.bmp");

//    vector<vector<double>> matrix{{ 0, 0, 0, 1 }, {1, 1, 1, 1}, { 0, -1, 0, -1}, {1, 0, 0, 0}};
    vector<vector<double>> matrix{{1, 2, -1}, {-3, -1, 3}, {2, 1, -1}};
    vector<vector<double>> adj = adjacencyCalculator(matrix);
    double det = determinant(matrix);
    auto trans = transposedMatrix(adj);
    auto inv = inverseMatrix(trans, det);

    return 0;
}



