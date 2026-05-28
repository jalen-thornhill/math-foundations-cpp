#pragma once


class CalculusTool
{
private:
    /* data */
public:
    CalculusTool(/* args */);
    ~CalculusTool();
    
    double evaluateFunction(int functionChoice, double x);
    double derivativeAt(int functionChoice, double x);
    double integrateTrapezoid(int functionChoice, double a, double b, int n);


    void printLimitTable(int functionChoice, double target);
};


