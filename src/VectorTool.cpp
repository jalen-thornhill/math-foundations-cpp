#include "VectorTool.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

VectorTool::VectorTool(/* args */){
}

vector<double> VectorTool::addVectors(vector<double> a, vector<double> b) {
try{

        if (a.empty() || b.empty()) {
        throw invalid_argument("Vectors cannot be empty.");
    }

    if (a.size() != b.size()) {
        throw invalid_argument("Vectors must be of the same size for addition.");
    }



 } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return vector<double>(); // Return an empty vector on error
}

    vector<double> result;



    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back(a[i] + b[i]);
    }       

    return result;
}

vector<double> VectorTool::subtractVectors(vector<double> a, vector<double> b) {
try{

        if (a.empty() || b.empty()) {
        throw invalid_argument("Vectors cannot be empty.");
    }

    if (a.size() != b.size()) {
        throw invalid_argument("Vectors must be of the same size for subtraction.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return vector<double>(); // Return an empty vector on error
}

    vector<double> result;

    for (size_t i = 0; i < a.size(); ++i) {
        result.push_back(a[i] - b[i]);
    }

    return result;
}

vector<double> VectorTool::scalarMultiply(double scalar, vector<double> v) {
try{

        if (v.empty()) {
        throw invalid_argument("Vector cannot be empty.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return vector<double>(); // Return an empty vector on error
}

    vector<double> result;

    for (size_t i = 0; i < v.size(); ++i) {
        result.push_back(scalar * v[i]);
    }

    return result;
}

double VectorTool::dotProduct(vector<double> a, vector<double> b) {
try{

        if (a.empty() || b.empty()) {
        throw invalid_argument("Vectors cannot be empty.");
    }

    if (a.size() != b.size()) {
        throw invalid_argument("Vectors must be of the same size for dot product.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return 0.0; // Return 0 on error
}

    double result = 0.0;

    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }

    return result;
}


double VectorTool::magnitude(vector<double> v) {
try{

        if (v.empty()) {
        throw invalid_argument("Vector cannot be empty.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return 0.0; // Return 0 on error
}

    double sumOfSquares = 0.0;

    for (size_t i = 0; i < v.size(); ++i) {
        sumOfSquares += v[i] * v[i];
    }

    return sqrt(sumOfSquares);
}

bool VectorTool::sameDimension(vector<double> a, vector<double> b) {
    return a.size() == b.size();
}

bool VectorTool::arePerpendicular(vector<double> a, vector<double> b) {
    if(!sameDimension(a, b)) {
        cerr << "Error: Vectors must be of the same size to check for perpendicularity." << endl;
        return false; // Return false if vectors are of different sizes
    }

    return abs(dotProduct(a, b)) < 0.000001; // Consider them perpendicular if the dot product is close to zero
}

void VectorTool::printVector(vector<double> v) {
    cout << "(";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << ")" << endl;
}
