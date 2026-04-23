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

        case '**': return 3;
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
        case '**': return pow(a,b);
        case '%': return fmod(a,b);
        default: return 0;

    }
}

double evaluate(string input) // evaluate via tokens found in the input by priority
// MAIN EVALUATION FUNCTION
{

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
    

    return 0;
}

