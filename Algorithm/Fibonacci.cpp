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

	int Fibonacci::Fibonacci_By_Recursion(int aimNumber)
	{
		if (aimNumber < 2) return aimNumber;

		return Fibonacci_By_Recursion(aimNumber - 1) + Fibonacci_By_Recursion(aimNumber - 2);
	}

	int Fibonacci::Fibonacci_Top_Down_Init(int aimNumber)
	{
		if (aimNumber <= 0) return aimNumber;

		// 배열 초기화.
		if (array_Initialize(aimNumber + 1) != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		_resultMemo[0] = 0;
		_resultMemo[1] = 1;
		
		auto retval = Fibonacci_Top_Down_Recur(aimNumber);

		// 할당한 배열 해제.
		if (array_Release() != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		return retval;
	}

	int Fibonacci::Fibonacci_Top_Down_Recur(int aimNumber)
	{
		// 계산해 놓은 기록이 있다면 바로 반환.
		if (_resultMemo[aimNumber] != -1)
		{
			return _resultMemo[aimNumber];
		}

		// 없다면 재귀 호출.
		_resultMemo[aimNumber] = Fibonacci_Top_Down_Recur(aimNumber - 1) + Fibonacci_Top_Down_Recur(aimNumber - 2);

		return _resultMemo[aimNumber];
	}

	int Fibonacci::Fibonacci_Botton_Up(int aimNumber)
	{
		if (aimNumber < 0) return -1;

		// 배열 초기화.
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

		// 할당한 배열 해제.
		if (array_Release() != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		return retval;
	}

	FIBONACCI_RESULT Fibonacci::array_Initialize(const int size)
	{
		// 배열이 이미 만들어진 상태라면 에러 반환.
		if (_resultMemo != nullptr)
		{
			return FIBONACCI_RESULT::ARRAY_ALLOC_ALREADY;
		}

		// 만들어진 상황이 아니라면 사이즈만큼 할당.
		_resultMemo = new int[size];
		
		// 할당한 메모를 -1로 초기화.
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