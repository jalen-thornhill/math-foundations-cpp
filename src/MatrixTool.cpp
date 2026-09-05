#include "MatrixTool.hpp"
#include <iostream>
using namespace std;


void   MatrixTool::printMatrix(const vector<vector<double>>& matrix){
    // I am checking for an empty matrix before displaying its elements one row at a time.


    if (matrix.empty()){
        cerr << "Matrix is empty  \n";
        return;
    }

    for(auto& idx : matrix){
        for(auto& num : idx){
            cout << num<< " ";
        }
          cout << "\n";
    }
  
        
    
    
}


bool MatrixTool::sameSize(vector<vector<double>>& matrixA, vector<vector<double>>& matrixB){
    // I am rejecting empty matrices and comparing their row counts and corresponding row lengths.

    if (matrixA.empty() || matrixB.empty()){
        cerr << "One of the matrices is empty  \n";
        return false;
    }

    if (matrixA.size() != matrixB.size()){
        return false;
    }

    



        for (int row = 0; row < matrixA.size(); row++) {
        if (matrixA[row].size() != matrixB[row].size()) {
            return false;
        }


       
}
 return true;
}


vector<vector<double>> MatrixTool::addMatrices( vector<vector<double>>& matrixA,  vector<vector<double>>& matrixB){
    // I am checking for matching sizes and returning an empty result if the matrices cannot be added.
    

    if (!sameSize(matrixA, matrixB)){
        cerr << "Matrices must be of the same size for addition  \n";
        return vector<vector<double>>();
    }

    vector<vector<double>> res;

    for (int row = 0; row < matrixA.size(); row++) {
        vector<double> resRow;
        for (int col = 0; col < matrixA[row].size(); col++) {
            // I am adding elements at the same row and column to build each result row.
            resRow.push_back(matrixA[row][col] + matrixB[row][col]);
        }

        res.push_back(resRow);
    }

    return res;
}


vector<vector<double>> MatrixTool::subtractMatrices( vector<vector<double>>& matrixA,  vector<vector<double>>& matrixB){
    // I am checking for matching sizes and returning an empty result if the matrices cannot be subtracted.
    

    if (!sameSize(matrixA, matrixB)){
        cerr << "Matrices must be of the same size for subtraction  \n";
        return vector<vector<double>>();
    }

    vector<vector<double>> res;

    for (int row = 0; row < matrixA.size(); row++) {
        vector<double> resRow;
        for (int col = 0; col < matrixA[row].size(); col++) {
            // I am subtracting each element of the second matrix from the matching element of the first.
            resRow.push_back(matrixA[row][col] - matrixB[row][col]);
        }

        res.push_back(resRow);
    }

    return res;
}

vector<vector<double>> MatrixTool::scalarMultiplyMatrix(double scalar, vector<vector<double>>& matrix){
    // I am checking for an empty matrix before multiplying every element by the same number.
    if (matrix.empty()){
        cerr << "Matrix is empty  \n";
        return vector<vector<double>>();
    }
    
    vector<vector<double>> res;

    for (int row = 0; row < matrix.size(); row++) {
        vector<double> resRow;
        for (int col = 0; col < matrix[row].size(); col++) {
            resRow.push_back(scalar * matrix[row][col]);
        }

        res.push_back(resRow);
    }

    return res;
}



vector<vector<double>> MatrixTool::transposeMatrix( vector<vector<double>>& matrix){
    // I am exchanging rows and columns, assuming every row has the same number of elements.


        if (matrix.empty()) {
        cerr << "Matrix is empty\n";
        return vector<vector<double>>();
    }

    // I am creating one result row for each column of the original matrix.
    vector<vector<double>> res(matrix[0].size());

    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            res[col].push_back(matrix[row][col]);
        }
    }

    return res;

}

vector<vector<double>> MatrixTool::multiplyMatrices( vector<vector<double>>& matrixA,  vector<vector<double>>& matrixB){
    // I am checking for empty matrices before checking whether their dimensions allow multiplication.
    // I am assuming each matrix is rectangular, with equally sized rows within that matrix.
    if (matrixA.empty() || matrixB.empty()){
        cerr << "One of the matrices is empty  \n";
        return vector<vector<double>>();
    }

    // I am comparing the first matrix's column count with the second matrix's row count.
    if (matrixA[0].size() != matrixB.size()){
        cerr << "Number of columns in the first matrix must equal the number of rows in the second matrix for multiplication  \n";
        return vector<vector<double>>();
    }

    vector<vector<double>> res;

    for (int row = 0; row < matrixA.size(); row++) {
        vector<double> resRow;
        for (int col = 0; col < matrixB[0].size(); col++) {
            // I am calculating each result element by multiplying a row by a column and adding the products.
            double sum = 0;
            for (int k = 0; k < matrixA[row].size(); k++) {
                sum += matrixA[row][k] * matrixB[k][col];
            }
            resRow.push_back(sum);
        }
        res.push_back(resRow);
    }

    return res;
}
