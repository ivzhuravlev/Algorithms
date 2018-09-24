#pragma once

namespace UnionFind
{
	class UnionFindBase
	{
		virtual void makeUnion(unsigned a, unsigned b) = 0;
		virtual bool isConnected(unsigned a, unsigned b) = 0;
	};
}