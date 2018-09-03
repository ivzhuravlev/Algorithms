#pragma once

#include "UnionFind.h"

#include <vector>

namespace UnionFind
{
	class QuickUnion : public UnionFind
	{
		public:
			QuickUnion(unsigned length);
			virtual void makeUnion(unsigned a, unsigned b) override;
			virtual bool isConnected(unsigned a, unsigned b) override;
		
		protected:
			virtual unsigned findRoot(unsigned i);
			
			std::vector<unsigned> _arr;
	};
}