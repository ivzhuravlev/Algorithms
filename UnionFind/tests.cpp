#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "QuickFind.h"
#include "QuickUnion.h"

using namespace UnionFind;

TEST_CASE("UnionFindDisjointSet with QuickFind realization", "[QuickFind]")
{
	const unsigned N = 10;
	QuickFind qf(10);
	
	qf.makeUnion(0, 5);
	qf.makeUnion(5, 6);
	qf.makeUnion(1, 2);
	qf.makeUnion(3, 8);
	qf.makeUnion(5, 6);
	qf.makeUnion(1, 7);
	qf.makeUnion(5, 6);
	qf.makeUnion(4, 9);
	qf.makeUnion(3, 4);
	
	CHECK(qf.isConnected(0, 6) == true);
	CHECK(qf.isConnected(1, 7) == true);
	CHECK(qf.isConnected(3, 9) == true);
	
	CHECK(qf.isConnected(0, 1) == false);
	CHECK(qf.isConnected(2, 3) == false);
	CHECK(qf.isConnected(7, 9) == false);
}

TEST_CASE("UnionFindDisjointSet with QuickUnion realization", "[QuickUnion]")
{
	const unsigned N = 10;
	QuickFind qu(10);
	
	qu.makeUnion(0, 5);
	qu.makeUnion(5, 6);
	qu.makeUnion(1, 2);
	qu.makeUnion(3, 8);
	qu.makeUnion(5, 6);
	qu.makeUnion(1, 7);
	qu.makeUnion(5, 6);
	qu.makeUnion(4, 9);
	qu.makeUnion(3, 4);
	
	CHECK(qu.isConnected(0, 6) == true);
	CHECK(qu.isConnected(1, 7) == true);
	CHECK(qu.isConnected(3, 9) == true);
	
	CHECK(qu.isConnected(0, 1) == false);
	CHECK(qu.isConnected(2, 3) == false);
	CHECK(qu.isConnected(7, 9) == false);
}