#include "lexer.h"

lexer::lexer(std::string str) {
	text = str;
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
}

double get_double() {
	double val = 0;
	bool pre_decimal = true;
	int digit_counter = 0;
	while(current_char == '.' || (current_char >= '0' && current_char <= '9') {
		if(current_char == '.') {
			if(pre_decimal) return val;
			pre_decimal = false;
		} else if(pre_decimal) {
			val *= 10;
			val += (int)(current_char - '0');
		} else {
			val += ((int)(current_char - '0'))/pow(10, ++digitCounter);
		}
		if(!advance()) return val;
	}
	return val;
}

int main(int argc, char** argv) {}
