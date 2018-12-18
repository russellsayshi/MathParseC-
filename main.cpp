#include <iostream>
#include <string>
#include <unordered_map>
#include "lexer.h"
#include "interpreter.h"

int main(int argc, char** argv) {
	interpreter i;
	std::string input;
	std::unordered_map<std::string, double> vars;
	vars["x"] = 5;
	vars["pi"] = 3.14159265359;
	vars["e"] = 2.71828182846;
	while(1) {
		std::getline(std::cin, input);
		lexer lex(input);
		i.fetch_tokens(lex);
		std::cout << i.interpret(vars) << std::endl;
	}
}
