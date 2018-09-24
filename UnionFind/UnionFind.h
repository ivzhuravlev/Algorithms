#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

class UnionFind
{
public:
	UnionFind(unsigned length)
	{
		_parent.reserve(length);
		std::generate_n(std::back_inserter(_parent), length, [n = 0] () mutable { return n++; });

		_size.reserve(length);
		std::fill_n(std::back_inserter(_size), length, 1);
	}

	bool isConnected(unsigned i, unsigned j)
	{
		return root(i - 1) == root(j - 1);
	}

	void makeUnion(unsigned i, unsigned j)
	{
		if (isConnected(i, j))
			return;

		unsigned a = root(i - 1);
		unsigned b = root(j - 1);
		
		if (_size[a] > _size[b])
		{
			_parent[b] = a;
			_size[a] += _size[b];
		}
		else
		{
			_parent[a] = b;
			_size[b] += _size[a];
		}
	}

private:
	unsigned root(unsigned i)
	{
		while (i != _parent[i])
		{
			_parent[i] = _parent[_parent[i]];
			i = _parent[i];
		}
			
		return i;
	}

	std::vector<unsigned> _parent;
	std::vector<unsigned> _size;
};
