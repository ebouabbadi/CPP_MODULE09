#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int evaluateRPN(std::string rpn) {
    std::stringstream ss(rpn);
    std::stack<int> st;

    std::string element;
    while (ss >> element)
    {
        if (isdigit(element[0]))
        {
            int operand;
            stoi(element);
            st.push(operand); // push the operand onto the stack
        }
        else { // if the element is an operator
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();
            int result;
            switch (element[0]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: return -1; // unknown operator
            }
            st.push(result); // push the result back onto the stack
        }
    }
    
    // the result is the last element on the stack
    return st.top();
}

int main() {
    std::string rpn = "8 9 * 9 - 9 - 9 - 9";
    int result = evaluateRPN(rpn);
    std::cout << "Result = " << result << std::endl;
    return 0;
}
