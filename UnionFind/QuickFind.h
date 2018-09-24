#pragma once

#include "UnionFindBase.h"

#include <vector>

namespace UnionFind
{
	class QuickFind : public UnionFindBase
	{
		public:
			QuickFind(unsigned length);
			
			virtual void makeUnion(unsigned a, unsigned b) override;
			virtual bool isConnected(unsigned a, unsigned b) override;
			
		private:
			std::vector<unsigned> _arr;
	};
}