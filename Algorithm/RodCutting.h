#pragma once
#include <stdint.h>

namespace DynamicProgramming
{
	class RodCutting
	{
	public :
		
		RodCutting() = default;
		~RodCutting() {};

		// Brute Recursive Method
		int Brute_Rod_Cutting(int * priceList, int length);

		// Memoization Method
		int Memoization_Cutting(int * priceLiat, int length);

	private :

		int Memoization_Cutting_Recur(int * memo, int * pricetList, int length);

	};
}
