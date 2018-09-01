#pragma once

#include "UnionFind.h"

#include <vector>

namespace UnionFind
{
	class QuickFind : public UnionFind
	{
		public:
			QuickFind(unsigned length);
			
			virtual void makeUnion(unsigned a, unsigned b) override;
			virtual bool isConnected(unsigned a, unsigned b) const override;
			
		private:
			std::vector<unsigned> _arr;
	};
}