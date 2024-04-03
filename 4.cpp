#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
// Function to perform an operation based on the operator and return the result
int performOperation(int operand1, int operand2, char operation) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}

// Function to evaluate the postfix expression
int evaluatePostfixExpression(const std::string& expression) {
    stack<int> stack;
    
    for (char c : expression) {
        if (isdigit(c)) {
            // Convert char digit to int and push onto the stack
            stack.push(c - '0');
        } else {
            // Pop the top two elements for the operation
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            
            // Perform operation and push the result back onto the stack
            int result = performOperation(operand1, operand2, c);
            stack.push(result);
        }
    }
    
    // The final result should be the only item left in the stack
    return stack.top();
}

int main() {
    string expression = "23*4+10/2"; // Example postfix expression
    int result = evaluatePostfixExpression(expression);
    cout << "Result of Postfix Expression \"" << expression << "\" is: " << result << std::endl;
    return 0;
}
