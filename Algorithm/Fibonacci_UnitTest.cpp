#include "stdafx.h"
#include "CppUnitTest.h"

#include <stdint.h>

#include "Fibonacci.h"
#include "Util.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm
{		
	using Fibonacci = DynamicProgramming::Fibonacci;

	TEST_CLASS(Fibonacci_UnitTest)
	{
	public:

		// 피보나치 수열의 40번째 수.
		const int64_t fibonacci_fourty = 102334155;

		// 피보나치 관련 메소드들을 가지고 있는 객체.
		Fibonacci * _fibonacci = nullptr;
		
		// Brute-Force하게 재귀 함수를 호출하여 피보나치 수열의 값을 구하는 경우 유닛 테스트. 
		TEST_METHOD(Fibonacci_Brute)
		{
			_fibonacci = new Fibonacci();

			// Boundary Case : 0인 경우.
			auto retval = _fibonacci->Fibonacci_By_Recursion(0);
			int64_t expect = 0;
			Assert::IsTrue(expect == retval);

			// 각각 1, 2, 5, 10, 40번째 피보나치 수열의 수.
			retval = _fibonacci->Fibonacci_By_Recursion(1);
			expect = 1;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_By_Recursion(2);
			expect = 1;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_By_Recursion(5);
			expect = 5;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_By_Recursion(10);
			expect = 55;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_By_Recursion(40);
			expect = fibonacci_fourty;
			Assert::IsTrue(expect == retval);

			// Error Case : 0미만의 값이 들어간 경우.
			retval = _fibonacci->Fibonacci_By_Recursion(-1);
			expect = -1;
			Assert::IsTrue(expect == retval);

			delete _fibonacci;
		}

		// Memoization 방법을 이용한 Dynamic Programming중 Top-down 방식을 사용하는 방법.
		TEST_METHOD(Fibonacci_Dynamic_Top_Down)
		{
			_fibonacci = new Fibonacci();

			// Boundary Case : 0인 경우.
			auto retval = _fibonacci->Fibonacci_Top_Down_Init(0);
			int64_t expect = 0;
			Assert::IsTrue(expect == retval);

			// 각각 1, 2, 5, 10, 40번째 피보나치 수열의 수.
			retval = _fibonacci->Fibonacci_Top_Down_Init(1);
			expect = 1;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Top_Down_Init(2);
			expect = 1;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Top_Down_Init(5);
			expect = 5;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Top_Down_Init(10);
			expect = 55;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Top_Down_Init(40);
			expect = fibonacci_fourty;
			Assert::IsTrue(expect == retval);

			// Error Case : 0미만의 값이 들어간 경우.
			retval = _fibonacci->Fibonacci_Top_Down_Init(-1);
			expect = -1;
			Assert::IsTrue(expect == retval);

			delete _fibonacci;
		}

		// Memoization 방법을 이용한 Dynamic Programming중 Botton-up 방식을 사용하는 방법.
		TEST_METHOD(Fibonacci_Dynamic_Bottom_Up)
		{
			_fibonacci = new Fibonacci();

			// Boundary Case : 0인 경우.
			auto retval = _fibonacci->Fibonacci_Botton_Up(0);
			int64_t expect = 0;
			Assert::IsTrue(expect == retval);

			// 각각 1, 2, 5, 10, 40번째 피보나치 수열의 수.
			retval = _fibonacci->Fibonacci_Botton_Up(1);
			expect = 1;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Botton_Up(2);
			expect = 1;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Botton_Up(5);
			expect = 5;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Botton_Up(10);
			expect = 55;
			Assert::IsTrue(expect == retval);

			retval = _fibonacci->Fibonacci_Botton_Up(40);
			expect = fibonacci_fourty;
			Assert::IsTrue(expect == retval);

			// Error Case : 0미만의 값이 들어간 경우.
			retval = _fibonacci->Fibonacci_Botton_Up(-1);
			expect = -1;
			Assert::IsTrue(expect == retval);

			delete _fibonacci;;
		}
	};
}