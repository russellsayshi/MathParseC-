#ifndef LMPC_T_ADDITIVE_GROUP_H
#define LMPC_T_ADDITIVE_GROUP_H

#include "group.h"

namespace lmpc {
	namespace tree {
		class additive_group;
	};
};

class lmpc::tree::additive_group : public lmpc::tree::group {
public:
	additive_group();
	lmpc::tree::numeric eval(const lmpc::tree::vartable&) const override;
	lmpc::tree::node simplify() const override;
	void add_child(std::unique_ptr<lmpc::tree::node>&&);
};

#endif
