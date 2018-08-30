#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "QuickFind.h"

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