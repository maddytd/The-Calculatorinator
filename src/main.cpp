#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cctype>
#include <map>

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
        case '(': return 3;
    }
}

double operate(double a, double b, char op) // function for returning an operation
{
    switch (op) {
        case '+': return a + b; 
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
        case '%': return fmod(a,b);
        default: return 0;

    }
}

double evaluate(string input) {
    // Create two stacks for the values and operators
    stack<double> values;
    stack<char> operators;

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
        } 
        // If it's a '(', push to operator stack
        else if (input[i] == '(') {
            operators.push(input[i]);
        } 
        // If it's a ')', iterate until you find the '(' 
        else if (input[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(operate(val1, val2, op));
            }
            if (!operators.empty()) operators.pop(); // Remove '('
        } 
        else {
            // It's a Operator 
            while (!operators.empty() && priority(operators.top()) >= priority(input[i])) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(operate(val1, val2, op));
            }
            operators.push(input[i]);
        }
    }

    // Process remaining operators
    while (!operators.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(operate(val1, val2, op));
    }

    return values.top();
} 

std::ostream& bold_on(std::ostream& os) // creates macro for turning on and off bold
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

std::ostream& underline_on(std::ostream& os)
{
    return os << "\033[4m";
}

std::ostream& underline_off(std::ostream& os)
{
    return os << "\033[24m";
}

int main() 
{
    string input; // our workable string of operations, string for dynamic size

    cout << bold_on << "----- WELCOME TO THE " << underline_on << "CALCULATORINATOR " << underline_off << "-----\n" << bold_off;

    cout << "\t\t(Powered by C++)\n\tPlease enter your algorithm to calculate below\n";

    getline(cin,input); // cin disallows spaces, getline does

    input.erase(remove(input.begin(), input.end(), ' '), input.end()); // strips all spaces
    // input is now a string of the operations. String is INDEXABLE and ITERABLE.
    
    size_t pos;
    // Change '**' to '^' for the operate() function
    while ((pos = input.find("**")) != string::npos) {
        input.replace(pos, 2, "^");
    }

    // Run evaluation and output result
    try {
        double result = evaluate(input);
        cout << "Final Result: " << result << endl;
    } catch (...) {
        cout << "Error: There was a problem with your syntax." << endl;
    }

    return 0;
}

