#pragma once

#include <vector>
using namespace std;

// I am grouping the vector calculations, comparison checks, and display method in this class.
class VectorTool
{
private:

public:


// I am declaring the operations that return a new vector after addition, subtraction, or scaling.
vector<double> addVectors(vector<double> a, vector<double> b);
vector<double> subtractVectors(vector<double> a, vector<double> b);
vector<double> scalarMultiply(double scalar, vector<double> v);


// I am declaring the methods that calculate a dot product and a vector's length.
double dotProduct(vector<double> a, vector<double> b);
double magnitude(vector<double> v);


// I am declaring checks for matching dimensions and perpendicular vectors.
bool sameDimension(vector<double> a, vector<double> b);
bool arePerpendicular(vector<double> a, vector<double> b);

// I am declaring the method that displays a vector's elements in parentheses.
void printVector(vector<double> v);
};


