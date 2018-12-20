#ifndef MPC_LEXER_H
#define MPC_LEXER_H

#include <string>
#include <stdexcept>
#include <cmath>
#include "token.h"
#include "tokentype.h"

class lexer {
private:
	std::string text;
	unsigned int pos;
	char current_char;

	double get_double();
	std::string get_name();
	bool is_part_of_numeral(char);

public:
	lexer(std::string);
	bool advance(); //return value indicates if more characters exist
	void skip_whitespace();
	void reset();
	token get_next_token();
};

#endif
