#pragma once

#include<vector>
using namespace std;
// I am grouping matrix calculations, size checks, and display methods in this class.
class MatrixTool
{
private:
vector<vector<double>> matrix;
public:



    // I am declaring the method that displays each matrix row on a separate line.
    void printMatrix(const vector<vector<double>>& matrix);


    // I am declaring the check for matching row counts and matching lengths of corresponding rows.
    bool sameSize(vector<vector<double>>& matrixA, vector<vector<double>>& matrixB);


// I am declaring addition and subtraction methods that combine corresponding matrix elements.
vector<vector<double>> addMatrices( vector<vector<double>>& matrixA, vector<vector<double>>& matrixB);

vector<vector<double>> subtractMatrices( vector<vector<double>>& matrixA,
                                         vector<vector<double>>& matrixB);

// I am declaring the method that multiplies every matrix element by the same number.
vector<vector<double>> scalarMultiplyMatrix(double scalar,
                                             vector<vector<double>>& matrix);

// I am declaring the method that exchanges the rows and columns of a rectangular matrix.
vector<vector<double>> transposeMatrix( vector<vector<double>>& matrix);

// I am declaring the method that multiplies compatible rectangular matrices.
vector<vector<double>> multiplyMatrices( vector<vector<double>>& matrixA,
                                         vector<vector<double>>& matrixB);
};

