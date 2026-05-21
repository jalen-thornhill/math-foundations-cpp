#pragma once

class Logic
{
private:
    /* data */
public:
    Logic();
    ~Logic();
    
bool logicalNot(bool p);
bool logicalAnd(bool p, bool q);
bool logicalOr(bool p, bool q);
bool implies(bool p, bool q);
bool biconditional(bool p, bool q);

void printTruthTable();
};


