#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

//! Union-find data structure
/*! Class UnionFind represents union find disjoint set data structure.
 *  It is 1-based so its indices lies in a range [1, N], where N - is
 *	number sent into constructor. 
 *	This data structure uses size-based tree balancing and path compression.
 */

class UnionFind
{
public:
	//! Constructor
	/*! Construct takes one unsigned parameter - number of elements
	 *	in disjoint set
	 */
	UnionFind(unsigned length)
	{
		_parent.reserve(length);
		
		// analogue of possible std::iota_n()
		std::generate_n(std::back_inserter(_parent), length, [n = 0] () mutable { return n++; });

		_size.reserve(length);
		std::fill_n(std::back_inserter(_size), length, 1);
	}
	
	//! Checks if two elements are connected. Return false if indices are incorrect
	bool isConnected(unsigned i, unsigned j)
	{
		if(!check(i, j))
			return false;

		return root(i - 1) == root(j - 1);
	}
	
	//! Makes union of two non-connected elements
	void makeUnion(unsigned i, unsigned j)
	{
		if(!check(i, j))
			return;
		
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
	//! Checks for index correctness
	bool check(unsigned i, unsigned j)
	{
		if(i == 0 || i > _parent.size() || j == 0 || j > _parent.size())
			return false;
		else
			return true;
	}
	
	//! Finds a foot of element and compress path to the root
	unsigned root(unsigned i)
	{
		while (i != _parent[i])
		{
			_parent[i] = _parent[_parent[i]];
			i = _parent[i];
		}
			
		return i;
	}
	
	//! Contains indices of parents of each element
	std::vector<unsigned> _parent;
	
	//! Contains size of tree with current index as a root
	std::vector<unsigned> _size;
};
