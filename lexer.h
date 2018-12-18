#ifndef MPC_LEXER_H
#define MPC_LEXER_H

#include <string>
#include <exception>
#include <cmath>
#include "integer.h"

class lexer {
private:
	std::string text;
	unsigned int pos;
	char current_char;

	double get_double();

public:
	lexer(std::string);
	bool advance(); //return value indicates if more characters exist
	void skip_whitespace();
	token get_next_token();
};

#endif
