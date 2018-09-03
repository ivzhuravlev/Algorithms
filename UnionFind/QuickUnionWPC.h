#include "QuickUnion.h"

namespace UnionFind
{
	class QuickUnionWPC : public QuickUnion
	{
		public:
			QuickUnionWPC(unsigned length);
			
			virtual void makeUnion(unsigned a, unsigned b) override;
			
		protected:
			virtual unsigned findRoot(unsigned i) override;
			void addTree(unsigned i, unsigned j);
			std::vector<unsigned> _size;
	};
}