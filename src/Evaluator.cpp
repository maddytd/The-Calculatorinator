#include "Evaluator.h"

#include <cmath>
#include <cctype>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

int priority(char op) // figure the priority of the operation via order of operations
{
    switch (op) {
        case '+': return 1;
        case '-': return 1;

        case '*': return 2;
        case '/': return 2;
        case '%': return 2;

        case '^': return 3;
        case '~': return 4; // Unary minus
        default: return 0;
    }
}

double operate(double a, double b, char op) // function for returning an operation
{
    switch (op) {
        case '+': return a + b; 
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw invalid_argument("Division by zero. ");
            }

            return a / b;
        case '^': return pow(a,b);
        case '%':
            if (b == 0) {
                throw invalid_argument("Modulo by zero. ");
            }
            
            return fmod(a, b);
        default: return 0;

    }
}

void processTopElements(stack<double>& values, stack<char>& operators) {
    if (operators.empty()) return;
    
    char op = operators.top();
    operators.pop();

    if (op == '~') {
        double val = values.top();
        values.pop();
        values.push(-val);
    } else {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        values.push(operate(val1, val2, op));
    }
}

double evaluate(string input) {
    // Create two stacks for the values and operators
    stack<double> values;
    stack<char> operators;

    // Toggle if a operator could be a Unary operator
    bool expecting_operand = true; // At the start ex. -5-8

    for (int i = 0; i < input.length(); i++) {
        // If it's a number, parse the full value (e.i. decimal value or values larger than two digits)
        if (isdigit(input[i])) {
            string valStr;
            while (i < input.length() && (isdigit(input[i]) || input[i] == '.')) {
                valStr += input[i++];
            }
            // Convert string to double and push to values stack
            values.push(stod(valStr));
            i--; // Adjust for the outer loop increment
            expecting_operand = false;
        } 
        // If it's a '(', push to operator stack
        else if (input[i] == '(') {
            operators.push(input[i]);
            expecting_operand = true; // After '(' ex. 2+(-3-4)
        } 
        // If it's a ')', iterate until you find the '(' 
        else if (input[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                processTopElements(values, operators);
            }
            if (!operators.empty()) operators.pop(); // Remove '('
            expecting_operand = false;
        } 
        else {
            char currentOp = input[i];

            if (expecting_operand) {
                if (currentOp == '-') {
                    operators.push('~'); // Unary Minus
                } else if (currentOp == '+') {
                    // ignore +val is just val
                }
            } else {
                // Binary Operator logic
                while (!operators.empty() && operators.top() != '(' && priority(operators.top()) >= priority(currentOp)) {
                    processTopElements(values, operators);
                }
                operators.push(currentOp);
            }
            expecting_operand = true; 
        }
    }

    // Process remaining operators
    while (!operators.empty()) {
        processTopElements(values, operators);
    }

    return values.top();
}
