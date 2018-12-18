#ifndef MPC_TOKEN_H
#define MPC_TOKEN_H

#include <string>
#include <ostream>
#include "tokentype.h"

class token {
private:
	tokentype type;
	double data;
	std::string name;

public:
	token(tokentype typ, double dat);
	token(tokentype typ, std::string nam);
	token(tokentype typ);

	tokentype get_type();
	double get_double_value();
	std::string get_string_value();

	friend std::ostream& operator<<(std::ostream& stream, token& tok);
};

#endif
