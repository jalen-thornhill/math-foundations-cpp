#pragma once


// I am grouping function evaluation and numerical calculus methods in this class.
class CalculusTool
{
private:
    // I am passing the values into each method instead of storing them as class data.
public:
    CalculusTool();
    ~CalculusTool();
    
    // I am declaring the method that evaluates one of the five supported functions.
    double evaluateFunction(int functionChoice, double x);
    // I am declaring the method that estimates a derivative from nearby function values.
    double derivativeAt(int functionChoice, double x);
    // I am declaring the method that estimates a definite integral using trapezoids.
    double integrateTrapezoid(int functionChoice, double a, double b, int n);


    // I am declaring the method that displays function values on both sides of a target.
    void printLimitTable(int functionChoice, double target);
};


