#include "MatrixTool.hpp"
#include <iostream>
using namespace std;


void   MatrixTool::printMatrix(const vector<vector<double>>& matrix){


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
    

    if (!sameSize(matrixA, matrixB)){
        cerr << "Matrices must be of the same size for addition  \n";
        return vector<vector<double>>();
    }

    vector<vector<double>> res;

    for (int row = 0; row < matrixA.size(); row++) {
        vector<double> resRow;
        for (int col = 0; col < matrixA[row].size(); col++) {
            resRow.push_back(matrixA[row][col] + matrixB[row][col]);
        }

        res.push_back(resRow);
    }

    return res;
}


vector<vector<double>> MatrixTool::subtractMatrices( vector<vector<double>>& matrixA,  vector<vector<double>>& matrixB){
    

    if (!sameSize(matrixA, matrixB)){
        cerr << "Matrices must be of the same size for subtraction  \n";
        return vector<vector<double>>();
    }

    vector<vector<double>> res;

    for (int row = 0; row < matrixA.size(); row++) {
        vector<double> resRow;
        for (int col = 0; col < matrixA[row].size(); col++) {
            resRow.push_back(matrixA[row][col] - matrixB[row][col]);
        }

        res.push_back(resRow);
    }

    return res;
}

vector<vector<double>> MatrixTool::scalarMultiplyMatrix(double scalar, vector<vector<double>>& matrix){
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


        if (matrix.empty()) {
        cerr << "Matrix is empty\n";
        return vector<vector<double>>();
    }

    vector<vector<double>> res(matrix[0].size());

    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            res[col].push_back(matrix[row][col]);
        }
    }

    return res;

}

vector<vector<double>> MatrixTool::multiplyMatrices( vector<vector<double>>& matrixA,  vector<vector<double>>& matrixB){
    if (matrixA.empty() || matrixB.empty()){
        cerr << "One of the matrices is empty  \n";
        return vector<vector<double>>();
    }

    if (matrixA[0].size() != matrixB.size()){
        cerr << "Number of columns in the first matrix must equal the number of rows in the second matrix for multiplication  \n";
        return vector<vector<double>>();
    }

    vector<vector<double>> res;

    for (int row = 0; row < matrixA.size(); row++) {
        vector<double> resRow;
        for (int col = 0; col < matrixB[0].size(); col++) {
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
