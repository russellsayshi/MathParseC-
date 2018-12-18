#ifndef MPC_INTEGER_H
#define MPC_INTEGER_H

#include "token.h"

class integer : public token {
	int value;
public:
	integer(int val) : value(val) {};
	int get_value();
};

#endif
