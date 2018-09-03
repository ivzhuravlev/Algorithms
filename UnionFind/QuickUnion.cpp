#include "QuickUnion.h"

using namespace UnionFind;

QuickUnion::QuickUnion(unsigned length)
{
	_arr.reserve(length);
	for(unsigned i = 0; i < length; ++i)
	{
		_arr.push_back(i);
	}
}

unsigned QuickUnion::findRoot(unsigned i)
{
	while(i != _arr[i])
		i = _arr[i];
	
	return i;
}

bool QuickUnion::isConnected(unsigned a, unsigned b)
{
	return findRoot(a) == findRoot(b);
}

void QuickUnion::makeUnion(unsigned a, unsigned b)
{
	_arr[findRoot(a)] = findRoot(b);
}

