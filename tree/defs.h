#ifndef LMPC_T_DEFS_H
#define LMPC_T_DEFS_H

#include <unordered_map>

namespace lmpc {
	namespace tree {
		typedef long double numeric;
		typedef std::unordered_map<std::string, numeric> vartable;
	};
};

#endif
