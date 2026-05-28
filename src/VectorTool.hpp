#pragma once

#include <vector>
using namespace std;

class VectorTool
{
private:

public:
    VectorTool();
    ~VectorTool();

    vector<double> addVectors(vector<double> a, vector<double> b);
vector<double> subtractVectors(vector<double> a, vector<double> b);
vector<double> scalarMultiply(double scalar, vector<double> v);


double dotProduct(vector<double> a, vector<double> b);
double magnitude(vector<double> v);


bool sameDimension(vector<double> a, vector<double> b);
bool arePerpendicular(vector<double> a, vector<double> b);

void printVector(vector<double> v);
};


