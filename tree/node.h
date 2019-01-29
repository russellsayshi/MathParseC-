#ifndef LMPC_T_NODE_H
#define LMPC_T_NODE_H

#include "defs.h"
#include <memory>

namespace lmpc {
	namespace tree {
		class node;
	};
};

class lmpc::tree::node {
public:
	virtual lmpc::tree::numeric eval(const lmpc::tree::vartable& table) const = 0;
	virtual std::shared_ptr<lmpc::tree::node> simplify() const = 0;
};

#endif
