#include "QuickUnionWPC.h"

#include <algorithm>
#include <iterator>

using namespace UnionFind;

QuickUnionWPC::QuickUnionWPC(unsigned length) :
	QuickUnion(length)
{
	_size.reserve(length);
	std::fill_n(back_inserter(_size), length, 1);
}

void QuickUnionWPC::makeUnion(unsigned a, unsigned b)
{
	unsigned i = findRoot(a);
	unsigned j = findRoot(b);
	
	if(_size[i] < _size[j])
	{
		addTree(i, j);
	}
	else
	{
		addTree(j, i);
	}
}

void QuickUnionWPC::addTree(unsigned i, unsigned j)
{
	_arr[i] = j;
	_size[j] += _size[i];
}

unsigned QuickUnionWPC::findRoot(unsigned i)
{
	while(i != _arr[i])
	{
		_arr[i] = _arr[_arr[i]];
		i = _arr[i];
	}
	return i;
}
	
