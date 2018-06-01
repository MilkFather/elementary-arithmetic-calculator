#ifndef CALC_HPP
#define CALC_HPP

#include <queue>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
#include <sstream>
#include "utils.hpp"

using namespace std;

double calculate(string expression);

queue<string> lexical(string s);
queue<token> tokenize(queue<string> x);
queue<token> RPNize(queue<token> inqueue);
double stackcalc(queue<token> exprpn);

#endif