#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>

#include "Fibonacci.h"
#include "Util.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Algorithm
{		
	using namespace DynamicProgramming;

	TEST_CLASS(Fibonacci_UnitTest)
	{
	public:

		// �Ǻ���ġ ���� �޼ҵ���� ������ �ִ� ��ü.
		Fibonacci * _fibonacci = nullptr;
		
		// Brute-Force�ϰ� ��� �Լ��� ȣ���Ͽ� �Ǻ���ġ ������ ���� ���ϴ� ��� ���� �׽�Ʈ. 
		TEST_METHOD(Fibonacci_Brute)
		{
			_fibonacci = new Fibonacci();

			auto retval = _fibonacci->Fibonacci_By_Recursion(0);
			Assert::AreEqual(0, retval);

			retval = _fibonacci->Fibonacci_By_Recursion(1);
			Assert::AreEqual(1, retval);

			retval = _fibonacci->Fibonacci_By_Recursion(2);
			Assert::AreEqual(1, retval);

			retval = _fibonacci->Fibonacci_By_Recursion(5);
			Assert::AreEqual(5, retval);

			retval = _fibonacci->Fibonacci_By_Recursion(10);
			Assert::AreEqual(55, retval);

			retval = _fibonacci->Fibonacci_By_Recursion(-1);
			Assert::AreEqual(-1, retval);

			delete _fibonacci;
		}

		// Memoization ����� �̿��� Dynamic Programming�� Top-down ����� ����ϴ� ���.
		TEST_METHOD(Fibonacci_Dynamic_Top_Down)
		{
			_fibonacci = new Fibonacci();

			delete _fibonacci;
		}

		// Memoization ����� �̿��� Dynamic Programming�� Botton-up ����� ����ϴ� ���.
		TEST_METHOD(Fibonacci_Dynamic_Bottom_Up)
		{
			_fibonacci = new Fibonacci();

			delete _fibonacci;
		}
	};
}