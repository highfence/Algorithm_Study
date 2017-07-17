#include "stdafx.h"
#include "CppUnitTest.h"
#include "Fibonacci.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm
{		
	using namespace DynamicProgramming;

	TEST_CLASS(Fibonacci_UnitTest)
	{
	public:

		Fibonacci* _fibonacci = nullptr;
		
		TEST_METHOD(Fibonacci_Brute)
		{
			_fibonacci = new Fibonacci;

			delete _fibonacci;
		}

	};
}