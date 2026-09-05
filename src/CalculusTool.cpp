
#include "CalculusTool.hpp"
#include <cmath>
#include<iostream>
#include <iomanip>
#include <vector>

using namespace std;

CalculusTool::CalculusTool() {}

CalculusTool::~CalculusTool() {}

    double CalculusTool::evaluateFunction(int functionChoice, double x){
        // I am evaluating the selected formula at x, using radians for sine and cosine.

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
            // I am reporting an unsupported function choice and returning zero.
            cerr <<"invalid choice \n";
            return 0;
        }
    }

    double CalculusTool::derivativeAt(int functionChoice, double x) {
    // I am using a step of 0.1 to sample the function near x.
    double h = 00000.1;

    // I am evaluating the function at equal distances on either side of x.
    double fxph = evaluateFunction(functionChoice, x + h);

    double fxmh = evaluateFunction(functionChoice, x - h);

    // I am estimating the slope with the central difference formula: (f(x+h) - f(x-h)) / (2h).
        double derivative = (fxph - fxmh) / (2 * h);

    return derivative;
}


void CalculusTool::printLimitTable(int functionChoice, double target) {

    // I am choosing points on both sides of the target to explore how the function behaves nearby.
    vector<double> offsets = {-0.1, -0.01, -0.001, 0.001, 0.01, 0.1};

    cout << "Limit Table for function choice " << functionChoice << " as x approaches " << target << ":\n";


    // I am displaying the sampled inputs and outputs in aligned columns with six decimal places.
        cout << fixed << setprecision(6)  << setw(15) << "x" << setw(15) << "f(x)" << endl;
    for (const auto& offset : offsets) {
        double x = target + offset;
        double y = evaluateFunction(functionChoice, x);
        cout << setw(15) << x << setw(15) << y << endl;   
}
}

double CalculusTool::integrateTrapezoid(int functionChoice, double a, double b, int n) {
    // I am checking for a positive subdivision count before calculating the step size.
 
if (n <= 0) {
        cerr << "Number of subdivisions must be greater than 0.\n";
        return 0;
    }
    // I am dividing the interval into n equal parts to set the width of each trapezoid.
    double h = (b-a) / n;

    // I am giving the endpoints half weight because each belongs to only one trapezoid.
    double total = (evaluateFunction(functionChoice, a) + evaluateFunction(functionChoice, b)) / 2.0;

    
    // I am adding the interior function values, which each contribute to two neighboring trapezoids.
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        total += evaluateFunction(functionChoice, x);
    }

    
    // I am multiplying the weighted sum by the step size to estimate the definite integral.
    return h * total;
}
