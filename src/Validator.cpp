#include "Validator.h"

#include <cctype>
#include <stdexcept>
#include <string>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

void validateInput(const string& input)
{
    if (input.empty()) {
        throw invalid_argument("Input cannot be empty.");
    }

    int balance = 0;
    char lastChar = '\0';

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (c == ' ') continue;

        // valid characters only
        if (!isdigit(c) && c != '.' &&
            c != '+' && c != '-' &&
            c != '*' && c != '/' &&
            c != '%' &&
            c != '(' && c != ')') {
            throw invalid_argument("Invalid character found.");
        }

        // Check for trailing dot (e.g., "5." instead of "5.0")
        if (c == '.' && i + 1 < input.length()) {
            char nextChar = input[i + 1];
            if (!isdigit(nextChar)) {
                throw invalid_argument("Invalid float value.");
            }
        }
        // Check for dot at the end of input
        if (c == '.' && i + 1 == input.length()) {
            throw invalid_argument("Invalid float value.");
        }

        if (c == '(') balance++;
        if (c == ')') {
            balance--;
            if (isOperator(lastChar)) {
                throw invalid_argument("Operator cannot be followed by closing parenthesis.");
            }
            // Check for empty parentheses
            if (lastChar == '(') {
                throw invalid_argument("Empty parentheses.");
            }
        }

        if (balance < 0) {
            throw invalid_argument("Unmatched parentheses.");
        }

        // expression cannot start with binary operator
        if (i == 0 && (c == '*' || c == '/' || c == '%')) {
            throw invalid_argument("Expression cannot start with operator.");
        }

        // missing operator: number followed by (
        if (i > 0 && c == '(' && isdigit(input[i - 1])) {
            throw invalid_argument("Missing operator before parenthesis.");
        }

        // two operators in a row (allow ** for power and - for unary minus)
        if (i > 0 && isOperator(c) && isOperator(input[i - 1])) {
            bool isValidSequence = (c == '*' && input[i - 1] == '*') ||  // ** is allowed
                                   (c == '-');  // - after any operator is allowed (unary minus)
            if (!isValidSequence) {
                throw invalid_argument("Invalid operator sequence.");
            }
        }

        lastChar = c; // Same pervious character
    }

    if (balance != 0) {
        throw invalid_argument("Unmatched parentheses.");
    }

    char last = input.back();

    if (isOperator(last)) {
        throw invalid_argument("Expression cannot end with operator.");
    }
}
