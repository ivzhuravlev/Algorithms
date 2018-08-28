#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../SingleElement/singleElement.h"

TEST_CASE("Finds single element in 4 elements array")
{
	int arr[] = { 3, 3, 2, 3 };
	int length = sizeof arr / sizeof arr[0];

	REQUIRE(BitwiseAlgorithms::findSingleElement(arr, length) == 2);
}

TEST_CASE("Finds single element in 12 elements array")
{
	int arr[] = { 12, 1, 12, 3, 12, 1, 1, 5, 3, 3 };
	int length = sizeof arr / sizeof arr[0];

	REQUIRE(BitwiseAlgorithms::findSingleElement(arr, length) == 5);
}