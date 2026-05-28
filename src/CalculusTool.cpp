
#include "CalculusTool.hpp"
#include <cmath>
#include<iostream>
#include <iomanip>
#include <vector>

using namespace std;

CalculusTool::CalculusTool() {}

CalculusTool::~CalculusTool() {}

    double CalculusTool::evaluateFunction(int functionChoice, double x){

        switch(functionChoice){
            case 1:
            return x*x;
            break;

            case 2:
            return x*x*x;
            break;

            case 3:
            return (2*x)+1;
            break;

            case 4:
            return sin(x);
            break;
            
            case 5:
            return cos(x);
            break;

            default:
            cerr <<"invalid choice \n";
            return 0;
        }
    }

    double CalculusTool::derivativeAt(int functionChoice, double x) {
    // set h to a small value
    double h = 00000.1;

    // calculate f(x + h)
    double fxph = evaluateFunction(functionChoice, x + h);

    // calculate f(x - h)
    double fxmh = evaluateFunction(functionChoice, x - h);

    // apply central difference formula
        double derivative = (fxph - fxmh) / (2 * h);
     // return result

    return derivative;
}


void CalculusTool::printLimitTable(int functionChoice, double target) {

    // offsets
    vector<double> offsets = {-0.1, -0.01, -0.001, 0.001, 0.01, 0.1};

    cout << "Limit Table for function choice " << functionChoice << " as x approaches " << target << ":\n";


        cout << fixed << setprecision(6)  << setw(15) << "x" << setw(15) << "f(x)" << endl;
    for (const auto& offset : offsets) {
        double x = target + offset;
        double y = evaluateFunction(functionChoice, x);
        cout << setw(15) << x << setw(15) << y << endl;   
}
}

double CalculusTool::integrateTrapezoid(int functionChoice, double a, double b, int n) {
 
if (n <= 0) {
        cerr << "Number of subdivisions must be greater than 0.\n";
        return 0;
    }
     //h = (b - a) / n;
    double h = (b-a) / n;

    double total = (evaluateFunction(functionChoice, a) + evaluateFunction(functionChoice, b)) / 2.0;

    
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        total += evaluateFunction(functionChoice, x);
    }

    
    return h * total;
}