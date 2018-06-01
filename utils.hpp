#ifndef UTILS_HPP
#define UTILS_HPP

#include <stdexcept>

extern const char operators[6];
extern const char operators_binary[4];
extern const char operators_unary[2];
extern const char numerics[11];
extern const int operators_count;
extern const int operators_binary_count;
extern const int operators_unary_count;
extern const int numerics_count;

typedef enum TOKENTYPE {number, unary, binary, bracket} tokentype;

typedef struct TOKEN {
	tokentype type;
	union {
		char o;
		double n;
	};
	int level;
	bool operator<= (const struct TOKEN rhs) const {
		if (this->type == number and rhs.type == number) return this->n <= rhs.n;
		else if (this->type == number or rhs.type == number) {
			throw std::invalid_argument("Invalid compare.");
		};

		if (this->level != rhs.level) return (this->level < rhs.level);
		else {
			// () ignored here
			// */
			// +-
			if (this->type == unary and rhs.type == unary) return false; // unary operators can overlap
            
			int thisl = 0, thatl = 0;
			if (this->o == '+' or this->o == '-') {
				if (this->type == binary) thisl = 1;
				else thisl = 2;
			}
			if (this->o == '*' or this->o == '/') thisl = 3;
			if (rhs.o == '+' or rhs.o == '-') {
				if (rhs.type == binary) thatl = 1;
				else thatl = 2;
			}
			if (rhs.o == '*' or rhs.o == '/') thatl = 3;
			return thisl <= thatl;
		}
	}
} token;

bool in(char x, const char inset[], int setsize);

#endif
