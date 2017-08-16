#pragma once
#include <stdint.h>

namespace DynamicProgramming
{
	typedef struct PriceMemo
	{
		int maxPrice = 0;
		int firstCutIdx = 0;
	};

	class RodCutting
	{
	public :
		
		RodCutting() = default;
		~RodCutting() {};

		// Brute Recursive Method
		int Brute_Rod_Cutting(int * priceList, int length);

		// Memoization Method
		int Memoization_Rod_Cutting(int * priceList, int length);

		// Bottom-Up Method
		int Bottom_Up_Rod_Cutting(int * priceList, int length);
	};
}
