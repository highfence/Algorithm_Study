#include "stdafx.h"
#include <stdint.h>

#include "RodCutting.h"

namespace DynamicProgramming
{
	int RodCutting::Brute_Rod_Cutting(int * priceList, int length)
	{
		if (length < 0 || priceList == nullptr)
		{
			return INT_MIN;
		}

		if (length == 0) return 0;

		int maxPrice = INT_MIN;
		for (int i = 0; i <= length; ++i)
		{
			int cuttingPrice = Brute_Rod_Cutting(priceList, length - i) + priceList[i];
			maxPrice = (maxPrice > cuttingPrice) ? maxPrice : cuttingPrice ;
		}

		return maxPrice;
	}
}