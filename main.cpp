#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include "calc.hpp"

using namespace std;

bool is_emptystr(string str) {
    for (int i = 0; i < str.length(); ++i) {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}

int main() {
    string test;
    while (true) {
        getline(cin, test);
        if (is_emptystr(test))
            break;
        try {
            cout << calculate(test) << endl;
        } catch (exception &e) {
            cout << "ERROR: " << e.what() << endl;
        }
    }
    return 0;
}
