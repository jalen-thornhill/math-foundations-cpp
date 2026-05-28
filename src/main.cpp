#include <iostream>
#include "Logic.hpp"
#include "CalculusTool.hpp"
#include "FunctionAnalyzer.hpp"
#include "VectorTool.hpp"
#include "MatrixTool.hpp"
#include <vector>

using namespace std;
int main(){
    Logic logic;
    FunctionAnalyzer functionAnalyzer;
    VectorTool vectorTool;
    MatrixTool matrixTool;
    CalculusTool calculusTool;

    // main menu loop



     cout << "My math foundations   \n";
    

     int choice;

    cout << "My Math Foundations\n";

    do {
        cout << "\n===== Main Menu =====\n";
        cout << "1. Logic Truth Tables\n";
        cout << "2. Function Analyzer\n";
        cout << "3. Vector Calculator\n";
        cout << "4. Matrix Calculator\n";
        cout << "5. Numerical Calculus Tools\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                logic.printTruthTable();
                break;

            case 2:
                functionAnalyzer.inputFunction();
                functionAnalyzer.printMapping();
                functionAnalyzer.printRange();

                cout << "Injective: " << (functionAnalyzer.isInjective() ? "Yes" : "No") << "\n";
                cout << "Surjective: " << (functionAnalyzer.isSurjective() ? "Yes" : "No") << "\n";
                cout << "Bijective: " << (functionAnalyzer.isBijective() ? "Yes" : "No") << "\n";
                break;

            case 3: {
                vector<double> a = {1, 2, 3};
                vector<double> b = {4, 5, 6};

                cout << "\nVector demo running...\n";

                vectorTool.printVector(vectorTool.addVectors(a, b));
                vectorTool.printVector(vectorTool.subtractVectors(a, b));
                vectorTool.printVector(vectorTool.scalarMultiply(2, a));

                cout << "Dot product: " << vectorTool.dotProduct(a, b) << "\n";
                cout << "Magnitude of a: " << vectorTool.magnitude(a) << "\n";
                cout << "Same dimension: " << (vectorTool.sameDimension(a, b) ? "Yes" : "No") << "\n";
                cout << "Perpendicular: " << (vectorTool.arePerpendicular(a, b) ? "Yes" : "No") << "\n";
                break;
            }

            case 4: {
                vector<vector<double>> A = {{1, 2}, {3, 4}};
                vector<vector<double>> B = {{5, 6}, {7, 8}};

                cout << "\nMatrix A:\n";
                matrixTool.printMatrix(A);

                cout << "\nMatrix B:\n";
                matrixTool.printMatrix(B);

                cout << "\nA + B:\n";
                matrixTool.printMatrix(matrixTool.addMatrices(A, B));

                cout << "\nA - B:\n";
                matrixTool.printMatrix(matrixTool.subtractMatrices(A, B));

                cout << "\n2A:\n";
                matrixTool.printMatrix(matrixTool.scalarMultiplyMatrix(2, A));

                cout << "\nTranspose of A:\n";
                matrixTool.printMatrix(matrixTool.transposeMatrix(A));

                cout << "\nA * B:\n";
                matrixTool.printMatrix(matrixTool.multiplyMatrices(A, B));
                break;
            }

            case 5: {
                int calcChoice;
                int functionChoice;
                double x, a, b;
                int n;

                cout << "\n===== Calculus Menu =====\n";
                cout << "1. Evaluate function\n";
                cout << "2. Estimate derivative\n";
                cout << "3. Print limit table\n";
                cout << "4. Estimate integral\n";
                cout << "Enter choice: ";
                cin >> calcChoice;

                cout << "\nChoose function:\n";
                cout << "1. x^2\n";
                cout << "2. x^3\n";
                cout << "3. 2x + 1\n";
                cout << "4. sin(x)\n";
                cout << "5. cos(x)\n";
                cout << "Enter function choice: ";
                cin >> functionChoice;

                switch (calcChoice) {
                    case 1:
                        cout << "Enter x: ";
                        cin >> x;
                        cout << "Result: " << calculusTool.evaluateFunction(functionChoice, x) << "\n";
                        break;

                    case 2:
                        cout << "Enter x: ";
                        cin >> x;
                        cout << "Derivative estimate: " << calculusTool.derivativeAt(functionChoice, x) << "\n";
                        break;

                    case 3:
                        cout << "Enter x value to approach: ";
                        cin >> x;
                        calculusTool.printLimitTable(functionChoice, x);
                        break;

                    case 4:
                        cout << "Enter a: ";
                        cin >> a;
                        cout << "Enter b: ";
                        cin >> b;
                        cout << "Enter subdivisions: ";
                        cin >> n;
                        cout << "Integral estimate: "
                             << calculusTool.integrateTrapezoid(functionChoice, a, b, n)
                             << "\n";
                        break;

                    default:
                        cout << "Invalid calculus choice.\n";
                        break;
                }

                break;
            }

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}
     


