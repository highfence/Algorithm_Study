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

		// �Ǻ���ġ ������ 40��° ��.
		const int64_t fibonacci_fourty = 102334155;

		// �Ǻ���ġ ���� �޼ҵ���� ������ �ִ� ��ü.
		Fibonacci * _fibonacci = nullptr;
		
		// Brute-Force�ϰ� ��� �Լ��� ȣ���Ͽ� �Ǻ���ġ ������ ���� ���ϴ� ��� ���� �׽�Ʈ. 
		TEST_METHOD(Fibonacci_Brute)
		{
			_fibonacci = new Fibonacci();

			// Boundary Case : 0�� ���.
			auto retval = _fibonacci->Fibonacci_By_Recursion(0);
			int64_t expect = 0;
			Assert::IsTrue(expect == retval);

			// ���� 1, 2, 5, 10, 40��° �Ǻ���ġ ������ ��.
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

			// Error Case : 0�̸��� ���� �� ���.
			retval = _fibonacci->Fibonacci_By_Recursion(-1);
			expect = -1;
			Assert::IsTrue(expect == retval);

			delete _fibonacci;
		}

		// Memoization ����� �̿��� Dynamic Programming�� Top-down ����� ����ϴ� ���.
		TEST_METHOD(Fibonacci_Dynamic_Top_Down)
		{
			_fibonacci = new Fibonacci();

			// Boundary Case : 0�� ���.
			auto retval = _fibonacci->Fibonacci_Top_Down_Init(0);
			int64_t expect = 0;
			Assert::IsTrue(expect == retval);

			// ���� 1, 2, 5, 10, 40��° �Ǻ���ġ ������ ��.
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

			// Error Case : 0�̸��� ���� �� ���.
			retval = _fibonacci->Fibonacci_Top_Down_Init(-1);
			expect = -1;
			Assert::IsTrue(expect == retval);

			delete _fibonacci;
		}

		// Memoization ����� �̿��� Dynamic Programming�� Botton-up ����� ����ϴ� ���.
		TEST_METHOD(Fibonacci_Dynamic_Bottom_Up)
		{
			_fibonacci = new Fibonacci();

			// Boundary Case : 0�� ���.
			auto retval = _fibonacci->Fibonacci_Botton_Up(0);
			int64_t expect = 0;
			Assert::IsTrue(expect == retval);

			// ���� 1, 2, 5, 10, 40��° �Ǻ���ġ ������ ��.
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

			// Error Case : 0�̸��� ���� �� ���.
			retval = _fibonacci->Fibonacci_Botton_Up(-1);
			expect = -1;
			Assert::IsTrue(expect == retval);

			delete _fibonacci;;
		}
	};
}