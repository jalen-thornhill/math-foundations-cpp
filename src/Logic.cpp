#include "Logic.hpp"
#include <iostream>


using namespace std;

// I am calculating the truth values for NOT, AND, OR, implication, and equivalence.
bool Logic::logicalNot(bool p){
    return !p;
}
bool Logic::logicalAnd(bool p, bool q){
    return p && q;
}
bool Logic::logicalOr(bool p, bool q){
    return p || q;
}
bool Logic::implies(bool p, bool q){
    return !p || q;
}
bool Logic::biconditional(bool p, bool q){
    return p == q;
}

Logic::Logic()
{
}

Logic::~Logic()
{
}

void Logic::printTruthTable(){
    // I am asking the user to choose the logical operation for the truth table.
    cout << "Select a logical operation:\n";
    cout << "1. NOT\n";
    cout << "2. AND\n";
    cout << "3. OR\n";
    cout << "4. IMPLIES\n";
    cout << "5. BICONDITIONAL\n";
    int choice;
    cin >> choice;
    // I am labeling the input and result columns so the table is easy to read.
    cout << "P Q Result\n";

    // I am using nested loops to generate all four pairs of true and false inputs.
    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            bool result;

            // I am applying the chosen operation to calculate the result for this row.
            switch (choice) {
                case 1:
                    result = logicalNot(p);
                    break;
                case 2:
                    result = logicalAnd(p, q);
                    break;
                case 3:
                    result = logicalOr(p, q);
                    break;
                case 4:
                    result = implies(p, q);
                    break;
                case 5:
                    result = biconditional(p, q);
                    break;
                default:
                    cout << "Invalid choice\n";
                    return;
            }
            cout << p << " " << q << " " << result << "\n\n\n";
        }
    }
}
