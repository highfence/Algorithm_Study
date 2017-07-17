#pragma once

namespace DynamicProgramming
{
	enum class FIBONACCI_RESULT : int
	{
		NONE,
		INVALID_INPUT,
		ARRAY_NOT_ALLOC_YET
	};

	class Fibonacci
	{
	public :

		Fibonacci() = default;
		~Fibonacci();

		// Brute-Force 하게 재귀 함수를 호출하는 방법.
		int Fibonacci_By_Recursion(int aimNumber);

		// Dynamic Programming
		int Fibonacci_Top_Down_Init(int aimNumber);
		int Fibonacci_Top_Down_Recur(int aimNumber);

		int Fibonacci_Botton_Up(int aimNumber);

	private :

		FIBONACCI_RESULT array_Initialize(const int size);
		FIBONACCI_RESULT array_Release();

	private :

		int * _resultMemo = nullptr;

	};
}