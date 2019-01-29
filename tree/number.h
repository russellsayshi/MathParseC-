#ifndef LMPC_T_NUMBER_H
#define LMPC_T_NUMBER_H

#include "defs.h"
#include "node.h"

namespace lmpc {
	namespace tree {
		class number;
	};
};

class lmpc::tree::number : public lmpc::tree::node {
private:
	const lmpc::tree::numeric value;

public:
	number(lmpc::tree::numeric);
	lmpc::tree::numeric eval(const lmpc::tree::vartable&) const override;
	std::shared_ptr<lmpc::tree::node> simplify() const override;
};

#endif
