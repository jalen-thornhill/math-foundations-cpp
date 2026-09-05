#pragma once

// I am grouping the Boolean operations and truth table display in this class.
class Logic
{
public:
    Logic();
    ~Logic();

// I am declaring the five logical operations used by the program.
bool logicalNot(bool p);
bool logicalAnd(bool p, bool q);
bool logicalOr(bool p, bool q);
bool implies(bool p, bool q);
bool biconditional(bool p, bool q);

// I am declaring the method that asks for an operation and displays its truth table.
void printTruthTable();
};


