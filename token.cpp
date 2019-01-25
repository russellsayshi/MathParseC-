#include <string>
#include "token.h"
#include "tokentype.h"

token::token(tokentype typ, long double dat) : type(typ), data(dat) {}
token::token(tokentype typ, std::string nam) : type(typ), name(nam) {}
token::token(tokentype typ) : token(typ, 0) {}

tokentype token::get_type() {
	return type;
}

long double token::get_double_value() {
	return data;
}

std::string token::get_string_value() {
	return name;
}


std::ostream& operator<<(std::ostream& stream, token& tok) {
	stream << "TOKEN(" << tok.get_type();
	if(tok.get_type() == DOUBLE) {
		stream << ", " << tok.get_double_value();
	} else if(tok.get_type() == VAR) {
		stream << ", " << tok.get_string_value();
	}
	stream << ")";
}
