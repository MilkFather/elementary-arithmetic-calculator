#include <iostream>
#include <string>
#include "calc.hpp"

using namespace std;

int main() {
	string test;
	getline(cin, test);
	cout << calculate(test) << endl;
	return 0;
}
