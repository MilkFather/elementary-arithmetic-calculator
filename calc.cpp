#include "calc.hpp"

double calculate(string expression) {
    return stackcalc(RPNize(tokenize(lexical(expression))));
}
