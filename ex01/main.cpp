#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: RPN <expression>" << endl;
        return 1;
    }

    istringstream iss(argv[1]);
    string token;
    stack<int> operands;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Ensure that there are at least two operands on the stack
            if (operands.size() < 2) {
                cerr << "Error: insufficient operands for operator " << token << endl;
                return 1;
            }

            // Pop the top two operands from the stack and apply the operator
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();

            if (token == "+") {
                operands.push(a + b);
            } else if (token == "-") {
                operands.push(a - b);
            } else if (token == "*") {
                operands.push(a * b);
            } else if (token == "/") {
                if (b == 0) {
                    cerr << "Error: division by zero" << endl;
                    return 1;
                }
                operands.push(a / b);
            }
        } else {
            // Parse the operand and push it onto the stack
            int operand;
            try {
                operand = stoi(token);
            } catch (invalid_argument&) {
                cerr << "Error: invalid operand " << token << endl;
                return 1;
            }
            operands.push(operand);
        }
    }

    // Ensure that there is exactly one operand on the stack
    if (operands.size() != 1) {
        cerr << "Error: too many operands" << endl;
        return 1;
    }

    // Output the result
    cout << operands.top() << endl;

    return 0;
}
