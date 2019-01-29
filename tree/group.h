#ifndef LMPC_T_GROUP_H
#define LMPC_T_GROUP_H

#include "defs.h"
#include "node.h"
#include <vector>
#include <memory>

namespace lmpc {
	namespace tree {
		class group;
	};
};

class lmpc::tree::group : public lmpc::tree::node {
protected:
	std::vector<std::unique_ptr<lmpc::tree::node>> children;

public:
	lmpc::tree::numeric eval(const lmpc::tree::vartable&) const override = 0;
	lmpc::tree::node simplify() const override = 0;
};

#endif
