#include <iostream>
#include "Logic.hpp"

using namespace std;
int main(){
    Logic logic;
    int choice;

     cout << "My math foundations   \n";
    
     


     
    do{
        cout << "1. Logic Truth Tables\n";
        cout << "2. Function Analyzer\n";
        cout << "3. Vector Calculator\n";
        cout << "4. Matrix Calculator\n";
        cout << "5. Numerical Calculus Tools\n";
        cout << "6. Export Session Report\n";
        cout << "0. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            logic.printTruthTable();
            break;
        
        default:
            break;
        }
    }while(choice != 0);
   

    return 0 ;
}