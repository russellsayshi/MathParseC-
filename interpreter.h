#ifndef MPC_INTERPRETER_H
#define MPC_INTERPRETER_H

#include <vector>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <utility>
#include <cmath>
#include "token.h"
#include "lexer.h"
#include "tokentype.h"

/**
 * GRAMMAR
 * GROUP: NUMERIC | L_PAREN ADDITIVE R_PAREN
 * ADDITIVE: MULTIPLICATIVE ((PLUS | MINUS) MULTIPLICATIVE)*
 * MULTIPLICATIVE: EXPONENTIAL ((MUL | DIV) EXPONENTIAL)*
 * EXPONENTIAL: GROUP | GROUP EXP EXPONENTIAL
 * NUMERIC: DOUBLE | MINUS EXPONENTIAL | VAR | SIN L_PAREN ADDITIVE R_PAREN | COS L_PAREN ADDITIVE R_PAREN
 */

class interpreter {
private:
	token current_token;
	unsigned int token_ptr;

	void eat(tokentype);
	double numeric_expression(const std::unordered_map<std::string, double>& vars);
	double group_expression(const std::unordered_map<std::string, double>& vars);
	double exponential_expression(const std::unordered_map<std::string, double>& vars);
	double multiplicative_expression(const std::unordered_map<std::string, double>& vars);
	double additive_expression(const std::unordered_map<std::string, double>& vars);
	std::vector<token> tokens;

public:
	interpreter();
	void fetch_tokens(lexer& lex);
	double interpret(const std::unordered_map<std::string, double>& map);
	
};

#endif
