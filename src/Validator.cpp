#include "Validator.h"

#include <cctype>
#include <stdexcept>
#include <string>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^';
}

void validateInput(const string& input)
{
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }

    int balance = 0;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (c == ' ') continue;

        // valid characters only
        if (!isdigit(c) && c != '.' &&
            c != '+' && c != '-' &&
            c != '*' && c != '/' &&
            c != '%' && c != '^' &&
            c != '(' && c != ')') {
            throw invalid_argument("Invalid character found.");
        }

        if (c == '(') balance++;
        if (c == ')') balance--;

        if (balance < 0) {
            throw invalid_argument("Unmatched parentheses.");
        }

        // expression cannot start with binary operator
        if (i == 0 && (c == '*' || c == '/' || c == '%' || c == '^')) {
            throw invalid_argument("Expression cannot start with operator.");
        }

        // missing operator: number followed by (
        if (i > 0 && c == '(' && isdigit(input[i - 1])) {
            throw invalid_argument("Missing operator before parenthesis.");
        }

        // two operators in a row
        if (i > 0 && isOperator(c) && isOperator(input[i - 1])) {
            throw invalid_argument("Invalid operator sequence.");
        }
    }

    if (balance != 0) {
        throw invalid_argument("Unmatched parentheses.");
    }

    char last = input.back();

    if (isOperator(last)) {
        throw invalid_argument("Expression cannot end with operator.");
    }
}
