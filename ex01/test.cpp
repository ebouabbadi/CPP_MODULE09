#include <iostream>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

double evaluateRPN(const string& expression) {
    vector<string> tokens;
    stringstream ss(expression);
    string token;

    while (ss >> token) {`
        tokens.push_back(token);
    }
 
    stack<double> operands;

    for (const auto& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            double result;
            if (token == "+")
                result = operand1 + operand2; 
            else if (token == "-")
                result = operand1 - operand2;
            else if (token == "*")
                result = operand1 * operand2;
            else if (token == "/")
                result = operand1 / operand2;

            operands.push(result);
        } else {
            double operand = stod(token);
            operands.push(operand);
        }
    }

    return operands.top();
}

int main() {
    string expression = "4 5 2 + *";
    double result = evaluateRPN(expression);
    cout << "Result: " << result << endl;

    return 0;
}
