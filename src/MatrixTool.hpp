#pragma once

#include<vector>
using namespace std;
class MatrixTool
{
private:
vector<vector<double>> matrix;
public:
    MatrixTool(/* args */);
    ~MatrixTool();


    void printMatrix(vector<vector<double>>& matrix);


    bool sameSize(vector<vector<double>>& matrixA, vector<vector<double>>& matrixB);


vector<vector<double>> addMatrices( vector<vector<double>>& matrixA, vector<vector<double>>& matrixB);

vector<vector<double>> subtractMatrices( vector<vector<double>>& matrixA,
                                         vector<vector<double>>& matrixB);

vector<vector<double>> scalarMultiplyMatrix(double scalar,
                                             vector<vector<double>>& matrix);

vector<vector<double>> transposeMatrix( vector<vector<double>>& matrix);

vector<vector<double>> multiplyMatrices( vector<vector<double>>& matrixA,
                                         vector<vector<double>>& matrixB);
};

