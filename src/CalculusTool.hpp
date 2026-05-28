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

    void printLimitTable(int functionChoice, double target);
};


