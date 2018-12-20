#include "lexer.h"

lexer::lexer(std::string str) {
	text = str;
	reset();
}

void lexer::reset() {
	pos = 0;
	current_char = text[pos];
}

bool lexer::advance() {
	pos++;
	if(pos >= text.size()) {
		current_char = -1;
		return false;
	} else {
		current_char = text[pos];
	}
	return true;
}

bool lexer::is_part_of_numeral(char c) {
	return c == '.' || (c >= '0' && c <= '9');
}

std::string lexer::get_name() {
	std::string ret;
	while(current_char >= 'a' && current_char <= 'z') {
		ret += current_char;
		if(!advance()) return ret;
	}
	return ret;
}

double lexer::get_double() {
	double val = 0;
	bool pre_decimal = true;
	int digit_counter = 0;
	while(is_part_of_numeral(current_char)) {
		if(current_char == '.') {
			if(!pre_decimal) return val;
			pre_decimal = false;
		} else if(pre_decimal) {
			val *= 10;
			val += (int)(current_char - '0');
		} else {
			val += ((int)(current_char - '0'))/pow(10, ++digit_counter);
		}
		if(!advance()) return val;
	}
	return val;
}

void lexer::skip_whitespace() {
	while(current_char == ' ' || current_char == '\t' || current_char == '\n' || current_char == '\r') {
		//whitespace
		if(!advance()) break;
	}
}

token lexer::get_next_token() {
	skip_whitespace();
	if(current_char == -1) {
		//hit end of line
		return token(T_EOF);
	} else if(is_part_of_numeral(current_char)) {
		return token(DOUBLE, get_double());
	} else if(current_char == '+') {
		advance();
		return token(PLUS);
	} else if(current_char == '-') {
		advance();
		return token(MINUS);
	} else if(current_char == '*') {
		advance();
		return token(MUL);
	} else if(current_char == '/') {
		advance();
		return token(DIV);
	} else if(current_char == '(') {
		advance();
		return token(L_PAREN);
	} else if(current_char == ')') {
		advance();
		return token(R_PAREN);
	} else if(current_char >= 'a' && current_char <= 'z') {
		std::string name = get_name();
		if(name == "sin") {
			return token(SIN);
		} else if(name == "cos") {
			return token(COS);
		} else {
			return token(VAR, name);
		}
	} else if(current_char == '^') {
		advance();
		return token(EXP);
	}
	throw std::runtime_error(std::string("Could not match character: ") + current_char);
}

