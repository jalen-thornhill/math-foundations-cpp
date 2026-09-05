#include "VectorTool.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;



vector<double> VectorTool::addVectors(vector<double> a, vector<double> b) {
// I am checking that both vectors contain elements and have matching sizes before adding them.
try{

        if (a.empty() || b.empty()) {
        throw invalid_argument("Vectors cannot be empty.");
    }

    if (a.size() != b.size()) {
        throw invalid_argument("Vectors must be of the same size for addition.");
    }



 } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return vector<double>(); // I am returning an empty vector because the inputs failed a check.
}

    vector<double> result;



    for (size_t i = 0; i < a.size(); ++i) {
        // I am adding the elements at the same position in both vectors.
        result.push_back(a[i] + b[i]);
    }       

    return result;
}

vector<double> VectorTool::subtractVectors(vector<double> a, vector<double> b) {
// I am checking that both vectors contain elements and have matching sizes before subtracting them.
try{

        if (a.empty() || b.empty()) {
        throw invalid_argument("Vectors cannot be empty.");
    }

    if (a.size() != b.size()) {
        throw invalid_argument("Vectors must be of the same size for subtraction.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return vector<double>(); // I am returning an empty vector because the inputs failed a check.
}

    vector<double> result;

    for (size_t i = 0; i < a.size(); ++i) {
        // I am subtracting each element of the second vector from the corresponding element of the first.
        result.push_back(a[i] - b[i]);
    }

    return result;
}

vector<double> VectorTool::scalarMultiply(double scalar, vector<double> v) {
// I am checking that the vector contains elements before scaling it.
try{

        if (v.empty()) {
        throw invalid_argument("Vector cannot be empty.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return vector<double>(); // I am returning an empty vector because the input failed the check.
}

    vector<double> result;

    for (size_t i = 0; i < v.size(); ++i) {
        // I am multiplying every element by the same number to scale the vector.
        result.push_back(scalar * v[i]);
    }

    return result;
}

double VectorTool::dotProduct(vector<double> a, vector<double> b) {
// I am checking for nonempty vectors with matching sizes before calculating the dot product.
try{

        if (a.empty() || b.empty()) {
        throw invalid_argument("Vectors cannot be empty.");
    }

    if (a.size() != b.size()) {
        throw invalid_argument("Vectors must be of the same size for dot product.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return 0.0; // I am returning zero after reporting the invalid input.
}

    // I am calculating the dot product by multiplying corresponding elements and adding the products.
    double result = 0.0;

    for (size_t i = 0; i < a.size(); ++i) {
        result += a[i] * b[i];
    }

    return result;
}


double VectorTool::magnitude(vector<double> v) {
// I am checking that the vector contains elements before calculating its length.
try{

        if (v.empty()) {
        throw invalid_argument("Vector cannot be empty.");
    }

    } catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
    return 0.0; // I am returning zero after reporting the empty vector.
}

    // I am calculating the vector's length by adding the squared elements and taking the square root.
    double sumOfSquares = 0.0;

    for (size_t i = 0; i < v.size(); ++i) {
        sumOfSquares += v[i] * v[i];
    }

    return sqrt(sumOfSquares);
}

bool VectorTool::sameDimension(vector<double> a, vector<double> b) {
    // I am comparing the number of elements in each vector to check their dimensions.
    return a.size() == b.size();
}

bool VectorTool::arePerpendicular(vector<double> a, vector<double> b) {
    // I am checking for matching dimensions before comparing the dot product with zero.
    if(!sameDimension(a, b)) {
        cerr << "Error: Vectors must be of the same size to check for perpendicularity." << endl;
        return false; // I am returning false because the vectors have different dimensions.
    }

    // I am allowing a small rounding difference by treating dot products close to zero as perpendicular.
    return abs(dotProduct(a, b)) < 0.000001;
}

void VectorTool::printVector(vector<double> v) {
    // I am displaying the elements in parentheses with commas between them.
    cout << "(";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1) {
            cout << ", ";
        }
    }
    cout << ")" << endl;
}
