#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stack>
#include <string>

using namespace std;
// using std::invalid_argument;
// using std::stack;
// using std::string;

int priority(char op);
double operate(double a, double b, char op);
void processTopElements(stack<double>& values, stack<char>& operators);
double evaluate(string input);

#endif
