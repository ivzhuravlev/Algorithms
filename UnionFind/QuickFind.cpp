#include "QuickFind.h"

using namespace UnionFind;

QuickFind::QuickFind(unsigned length)
{
	_arr.reserve(length);
	for(unsigned i = 0; i < length; ++i)
	{
		_arr.push_back(i);
	}
}

void QuickFind::makeUnion(unsigned a, unsigned b)
{
	unsigned indexToChange = _arr[a];
	unsigned indexNew = _arr[b];
	
	for(unsigned& i : _arr)
		if(i == indexToChange)
			i = indexNew;
}

bool QuickFind::isConnected(unsigned a, unsigned b)
{
	return _arr[a] == _arr[b];
}