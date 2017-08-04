#include <Windows.h>
#include <string>
#include <algorithm>

#include "stdafx.h"
#include "Fibonacci.h"

namespace DynamicProgramming
{
	Fibonacci::~Fibonacci()
	{
		if (_resultMemo != nullptr)
		{
			delete[] _resultMemo;
			_resultMemo = nullptr;
		}
	}

	int64_t Fibonacci::Fibonacci_By_Recursion(int aimNumber)
	{
		if (aimNumber < 2) return aimNumber;

		return Fibonacci_By_Recursion(aimNumber - 1) + Fibonacci_By_Recursion(aimNumber - 2);
	}

	int64_t Fibonacci::Fibonacci_Top_Down_Init(int aimNumber)
	{
		if (aimNumber <= 0) return aimNumber;

		// �迭 �ʱ�ȭ.
		if (array_Initialize(aimNumber + 1) != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		_resultMemo[0] = 0;
		_resultMemo[1] = 1;
		
		auto retval = Fibonacci_Top_Down_Recur(aimNumber);

		// �Ҵ��� �迭 ����.
		if (array_Release() != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		return retval;
	}

	int64_t Fibonacci::Fibonacci_Top_Down_Recur(int aimNumber)
	{
		// ����� ���� ����� �ִٸ� �ٷ� ��ȯ.
		if (_resultMemo[aimNumber] != -1)
		{
			return _resultMemo[aimNumber];
		}

		// ���ٸ� ��� ȣ��.
		_resultMemo[aimNumber] = Fibonacci_Top_Down_Recur(aimNumber - 1) + Fibonacci_Top_Down_Recur(aimNumber - 2);

		return _resultMemo[aimNumber];
	}

	int64_t Fibonacci::Fibonacci_Botton_Up(int aimNumber)
	{
		if (aimNumber <= 0) return aimNumber;

		// �迭 �ʱ�ȭ.
		if (array_Initialize(aimNumber + 1) != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		_resultMemo[0] = 0;
		_resultMemo[1] = 1;
		
		for (int i = 2; i <= aimNumber; ++i)
		{
			_resultMemo[i] = _resultMemo[i - 1] + _resultMemo[i - 2];
		}

		auto retval = _resultMemo[aimNumber];

		// �Ҵ��� �迭 ����.
		if (array_Release() != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		return retval;
	}

	FIBONACCI_RESULT Fibonacci::array_Initialize(const int size)
	{
		// �迭�� �̹� ������� ���¶�� ���� ��ȯ.
		if (_resultMemo != nullptr)
		{
			return FIBONACCI_RESULT::ARRAY_ALLOC_ALREADY;
		}

		// ������� ��Ȳ�� �ƴ϶�� �����ŭ �Ҵ�.
		_resultMemo = new int64_t[size];
		
		// �Ҵ��� �޸� -1�� �ʱ�ȭ.
		for (int i = 0; i < size; ++i)
		{
			_resultMemo[i] = -1;
		}

		return FIBONACCI_RESULT::NONE;
	}

	FIBONACCI_RESULT Fibonacci::array_Release()
	{
		if (_resultMemo != nullptr)
		{
			delete[] _resultMemo;
			_resultMemo = nullptr;
		}

		return FIBONACCI_RESULT::NONE;
	}
}