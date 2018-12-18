#include "interpreter.h"
#include <iostream>
#include <sstream>

interpreter::interpreter() : current_token(T_EOF) {}

void interpreter::fetch_tokens(lexer& lexer) {
	tokens.clear();
	while(1) {
		token t = lexer.get_next_token();
		tokens.push_back(t);
		if(t.get_type() == T_EOF) {
			break;
		}
	}
}

void interpreter::eat(tokentype tt) {
	if(current_token.get_type() == tt) {
		current_token = tokens[++token_ptr];
	} else {
		std::stringstream errormsg;
		errormsg << "Token required (TOKEN(" << tt << ")) did not match token given (" << current_token << ").";
		throw std::runtime_error(errormsg.str());
	}
}

double interpreter::group_expression(const std::unordered_map<std::string, double>& vars) {
	#ifdef DEBUG
	std::cout << "GROUP_EXPRESSION" << std::endl;
	#endif
	if(current_token.get_type() == L_PAREN) {
		eat(L_PAREN);
		double res = additive_expression(vars);
		eat(R_PAREN);
		return res;
	}
	double numres = numeric_expression(vars);
	return numres;
}

double interpreter::exponential_expression(const std::unordered_map<std::string, double>& vars) {
	#ifdef DEBUG
	#endif
	double g1 = group_expression(vars);
	if(current_token.get_type() == EXP) {
		eat(EXP);
		double g2 = exponential_expression(vars);
		return pow(g1, g2);
	}
	return g1;
}

double interpreter::numeric_expression(const std::unordered_map<std::string, double>& vars) {
	#ifdef DEBUG
	std::cout << "NUMERIC_EXPRESSION: " << current_token << std::endl;
	#endif
	if(current_token.get_type() == DOUBLE) {
		double val = current_token.get_double_value();
		eat(DOUBLE);
		return val;
	} else if(current_token.get_type() == MINUS) {
		eat(MINUS);
		double val = exponential_expression(vars);
		return -val;
	} else if(current_token.get_type() == VAR) {
		auto varit = vars.find(current_token.get_string_value());
		if(varit == vars.end()) {
			throw std::runtime_error(std::string("Variable with name '") + current_token.get_string_value() + std::string("' not found."));
		} else {
			eat(VAR);
			return std::get<1>(*varit);
		}
	} else if(current_token.get_type() == SIN) {
		eat(SIN);
		eat(L_PAREN);
		double v = additive_expression(vars);
		eat(R_PAREN);
		return sin(v);
	} else if(current_token.get_type() == COS) {
		eat(COS);
		eat(L_PAREN);
		double v = additive_expression(vars);
		eat(R_PAREN);
		return cos(v);
	}
	throw std::runtime_error("Logic has failed.");
}

double interpreter::additive_expression(const std::unordered_map<std::string, double>& vars) {
	#ifdef DEBUG
	std::cout << "ADDITIVE_EXPRESSION" << std::endl;
	#endif
	double res = multiplicative_expression(vars);

	while(current_token.get_type() == PLUS || current_token.get_type() == MINUS) {
		if(current_token.get_type() == PLUS) {
			eat(PLUS);
			res += multiplicative_expression(vars);
		} else {
			eat(MINUS);
			res -= multiplicative_expression(vars);
		}	
	}
	return res;
}

double interpreter::multiplicative_expression(const std::unordered_map<std::string, double>& vars) {
	#ifdef DEBUG
	std::cout << "MULTIPLICATIVE_EXPRESSION" << std::endl;
	#endif
	double res = exponential_expression(vars);

	while(current_token.get_type() == MUL || current_token.get_type() == DIV) {
		if(current_token.get_type() == MUL) {
			eat(MUL);
			res *= exponential_expression(vars);
		} else {
			eat(DIV);
			double tmp = exponential_expression(vars);
			if(tmp == 0) {
				throw std::runtime_error("Attempt to divide by zero.");
			}
			res /= tmp;
		}	
	}

	return res;
}

double interpreter::interpret(const std::unordered_map<std::string, double>& vars) {
	token_ptr = 0;
	if(tokens.size() <= 0) {
		return NAN;
	}
	current_token = tokens[0];
	double res = additive_expression(vars);
	if(token_ptr < tokens.size() - 1) {
		std::stringstream errormsg;
		errormsg << "Trailing token(s) left. Next: " << current_token;
		throw std::runtime_error(errormsg.str());
	}
	return res;
}
