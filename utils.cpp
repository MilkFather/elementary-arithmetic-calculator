#include "utils.hpp"

const char operators[6] = {'+', '-', '*', '/', '(', ')'};
const char operators_binary[4] = {'+', '-', '*', '/'};
const char operators_unary[2] = {'+', '-'};
const char numerics[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
const int operators_count = 6;
const int operators_binary_count = 4;
const int operators_unary_count = 2;
const int numerics_count = 11;

bool in(char x, const char inset[], int setsize) {
    for (int i = 0; i < setsize; i++)
        if (x == inset[i]) return true;
    return false;
}
