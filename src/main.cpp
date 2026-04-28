#include <algorithm>
#include <exception>
#include <iostream>
#include <string>

#include "Display.h"
#include "Evaluator.h"
#include "Validator.h"

using namespace std;

int main() 
{

    while(1){
    string input; // our workable string of operations, string for dynamic size

    cout << bold_on << "----- WELCOME TO THE " << underline_on << "CALCULATORINATOR " << underline_off << "-----\n" << bold_off;

    cout << "\t\t(Powered by C++)\n\tPlease enter your algorithm to calculate below\n";
    cout << "\t(If you want to exit/quit the program type 'q')\n";


    getline(cin,input); // cin disallows spaces, getline does

    input.erase(remove(input.begin(), input.end(), ' '), input.end()); // strips all spaces
    
    // Check if user wants to quit
    if (input == "q" || input == "Q") {
        cout << "Thank you for using the Calculatorinator!\n";
        break;
    }
    
    // input is now a string of the operations. String is INDEXABLE and ITERABLE.
    
    size_t pos;
    // Change '**' to '^' for the operate() function
    while ((pos = input.find("**")) != string::npos) {
        input.replace(pos, 2, "^");
    }

    // Run evaluation and output result
    try {
        validateInput(input);

        double result = evaluate(input);
        cout << "Final Result: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    }


    return 0;
}

