#include "calc.hpp"

/*
 Code referenced here:
 http://www.engr.mun.ca/~theo/Misc/exp_parsing.htm
 */

void procedure_E(queue<string> &q);
void procedure_P(queue<string> &q);

queue<token> tokened;

bool is_binary_operator(string x) {
    if (x.size() > 1) return false;
    return in(x[0], operators_binary, operators_binary_count);
}

bool is_unary_operator(string x) {
    if (x.size() > 1) return false;
    return in(x[0], operators_unary, operators_unary_count);
}

bool is_number(string x) {
    try {
        stod(x);
        return true;
    }
    catch (exception e) {
        return false;
    }
}

string next(queue<string> queue) {
    if (queue.empty()) return "END";
    else return queue.front();
}

void consume(queue<string> &inqueue, tokentype t) {
    token newtoken;
    newtoken.type = t;
    if (t == number) newtoken.n = stod(inqueue.front());
    else newtoken.o = inqueue.front()[0];
    inqueue.pop();
    tokened.push(newtoken);
}

void expect(string sym, queue<string> &inqueue) {
    if (next(inqueue) == sym) {
        if (sym == ")")
            consume(inqueue, bracket);
        else if (sym == "END")
            ;
    } else {
        stringstream os;
        os << "Expected '" << sym << "' but '" << next(inqueue) << "' found.";
        throw invalid_argument(os.str());
    }
}

void procedure_E(queue<string> &q) {
    procedure_P(q);
    while (is_binary_operator(next(q))) {
        consume(q, binary);
        procedure_P(q);
    }
}

void procedure_P(queue<string> &q) {
    if (is_number(next(q))) {
        consume(q, number);
    } else if (next(q) == "(") {
        consume(q, bracket);
        procedure_E(q);
        expect(")", q);
    } else if (is_unary_operator(next(q))) {
        consume(q, unary);
        procedure_P(q);
    } else {
        stringstream os;
        os << "Unrecongnized token '" << next(q) << "' here.";
        throw invalid_argument(os.str());
    }
}

queue<token> tokenize(queue<string> x) {
    tokened = queue<token>(); // clear it
    procedure_E(x);
    expect("END", x);
    return tokened;
}
