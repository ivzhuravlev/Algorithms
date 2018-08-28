#include "singleElement.h"

int BitwiseAlgorithms::findSingleElement(int arr[], int length)
{
	int ones = 0;
	int twos = 0;
	int commonBits = 0;

	for (int i = 0; i < length; ++i)
	{
		twos = twos | (ones & arr[i]);

		ones = ones ^ arr[i];

		commonBits = ~(ones & twos);

		ones = ones & commonBits;
		twos = twos & commonBits;
	}

	return ones;
}
