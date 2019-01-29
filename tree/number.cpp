#include "number.h"
#include "defs.h"

namespace lmpc {
	namespace tree {
		number::number(numeric _value) : value(_value) {}
		number::eval(const vartable&) {
			return value;
		}
		number::simplify() {
			return *this;
		}
	}
}

