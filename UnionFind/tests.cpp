#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "UnionFind.h"

TEST_CASE("UnionFind basic test", "[UnionFind]")
{
	const unsigned N = 10;
	UnionFind uf(N);
	
	uf.makeUnion(1, 6);
	uf.makeUnion(6, 7);
	uf.makeUnion(2, 3);
	uf.makeUnion(4, 9);
	uf.makeUnion(6, 7);
	uf.makeUnion(2, 8);
	uf.makeUnion(6, 7);
	uf.makeUnion(4, 5);
	uf.makeUnion(5, 10);
	
	
	CHECK(uf.isConnected(1, 7) == true);
	CHECK(uf.isConnected(2, 8) == true);
	CHECK(uf.isConnected(4, 10) == true);
	
	CHECK(uf.isConnected(1, 2) == false);
	CHECK(uf.isConnected(3, 4) == false);
	CHECK(uf.isConnected(8, 10) == false);
}