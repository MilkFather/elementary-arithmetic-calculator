#include "calc.hpp"

queue<token> RPNize(queue<token> inqueue) {
    // RPN (reverse polish notation) can be used to represent an expression.
    // However, instead of actually building the tree, the Shunting Yard algorithm is used.
    queue<token> rpnqueue;
    stack<token> operatorstack;
    int level = 1;
    while (!inqueue.empty()) {
        token thisone = inqueue.front();
        inqueue.pop();
        if (thisone.type == number)
            rpnqueue.push(thisone); // numbers just go through
        else {
            // for brackets, modify the operator level and discard them
            if (thisone.type == bracket) {
                if (thisone.o == '(') level++;
                else level--;
                continue;
            }
            thisone.level = level; // apply the operator level
            while (!operatorstack.empty() and thisone <= operatorstack.top()) {
                token o = operatorstack.top();
                operatorstack.pop();
                rpnqueue.push(o);
            }
            operatorstack.push(thisone);
        }
    }
    while (!operatorstack.empty()) {
        token o = operatorstack.top();
        operatorstack.pop();
        rpnqueue.push(o);
    }
    return rpnqueue;
}
