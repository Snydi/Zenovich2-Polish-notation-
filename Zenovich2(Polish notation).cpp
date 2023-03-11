#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    stack<int> operands;

    for (int i = input.size() - 1; i >= 0; i--) {
        char c = input[i];

        if (c == ' ') {
            continue;
        }

        if (isdigit(c)) {
            operands.push(c - '0');
        }
        else {
            int op1 = operands.top();
            operands.pop();
            int op2 = operands.top();
            operands.pop();

            switch (c) {
            case '+':
                operands.push(op1 + op2);
                break;
            case '-':
                operands.push(op1 - op2);
                break;
            case '*':
                operands.push(op1 * op2);
                break;
            case '/':
                
                if (op2 == 0) {
                    cout << "Error: division by zero" << endl;
                    exit(1);
                }
                operands.push(op2 / op1); // swap op1 and op2
                break;
            default:
                cout << "Invalid operator: " << c << endl;
                exit(1);
            }

        }
    }

    int result = operands.top();
    operands.pop();

    if (!operands.empty()) {
        cout << "Invalid expression" << endl;
        exit(1);
    }

    cout << "Result: " << result << endl;

    return 0;
}
