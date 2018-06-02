#include "calc.hpp"

double stackcalc(queue<token> exprpn) {
    stack<double> numberstack;
    while (!exprpn.empty()) {
        token thisone = exprpn.front();
        exprpn.pop();
        if (thisone.type == number)
            numberstack.push(thisone.n);
        else {
            try {
                if (thisone.type == unary) { // unary operator
                    double num = numberstack.top();
                    numberstack.pop();
                    switch (thisone.o) {
                        case '+':
                            numberstack.push(num);
                            break;
                        case '-':
                            numberstack.push(-num);
                            break;
                    }
                } else if (thisone.type == binary) { // binary operator
                    double num2 = numberstack.top();
                    numberstack.pop();
                    double num1 = numberstack.top();
                    numberstack.pop();
                    switch (thisone.o) {
                        case '+':
                            numberstack.push(num1 + num2);
                            break;
                        case '-':
                            numberstack.push(num1 - num2);
                            break;
                        case '*':
                            numberstack.push(num1 * num2);
                            break;
                        case '/':
                            numberstack.push(num1 / num2);
                            break;
                    }
                }
            }
            catch (exception e) {
                throw;
            }
        }
    }
    if (numberstack.size() != 1) {
        stringstream whatmsg;
        whatmsg << "Stack error: after calculation there are " << numberstack.size() << " numbers on the stack. Expected 1.";
        throw overflow_error(whatmsg.str());
    }
    return numberstack.top();
}
