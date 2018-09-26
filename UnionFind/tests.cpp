#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "UnionFind.h"

TEST_CASE("UnionFind", "[UnionFind]")
{
	const unsigned N = 10;
	UnionFind uf(N);
	
	uf.makeUnion(0, 5);
	uf.makeUnion(5, 6);
	uf.makeUnion(1, 2);
	uf.makeUnion(3, 8);
	uf.makeUnion(5, 6);
	uf.makeUnion(1, 7);
	uf.makeUnion(5, 6);
	uf.makeUnion(4, 9);
	uf.makeUnion(3, 4);
	
	REQUIRE(uf.isConnected(0, 6) == true);
	CHECK(uf.isConnected(1, 7) == true);
	CHECK(uf.isConnected(3, 9) == true);
	
	CHECK(uf.isConnected(0, 1) == false);
	CHECK(uf.isConnected(2, 3) == false);
	CHECK(uf.isConnected(7, 9) == false);
}