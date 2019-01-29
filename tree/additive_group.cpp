#include "additive_group.h"

namespace lmpc {
	namespace tree {
		additive_group::additive_group() {}
		void additive_group::add_child(std::unique_ptr<node>&& child) {
			children.push_back(std::move(child));
		}
	};
};
