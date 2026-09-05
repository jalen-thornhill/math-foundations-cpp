#pragma once


#include <vector>
using namespace std;


// I am grouping the data and methods for analyzing a finite function in this class.
class FunctionAnalyzer
{
private:
    // I am reserving separate vectors for inputs, allowed output values, and actual outputs.
    vector<int> domain;
    vector<char> codomain;
    vector<char> outputs;
public:
   // I am declaring the method that prints each distinct output value in the range.
   void printRange();

   // I am declaring checks for unique outputs, complete codomain coverage, and both properties together.
   bool isInjective();
   bool isSurjective();
   bool isBijective();

};


