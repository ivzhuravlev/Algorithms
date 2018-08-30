#pragma once

namespace UnionFind
{
	class UnionFind
	{
		virtual void makeUnion(unsigned a, unsigned b) = 0;
		virtual bool isConnected(unsigned a, unsigned b) const = 0;
	};
}