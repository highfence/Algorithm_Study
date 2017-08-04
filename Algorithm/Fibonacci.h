#pragma once

namespace DynamicProgramming
{
	enum class FIBONACCI_RESULT : int
	{
		NONE,
		INVALID_INPUT,
		ARRAY_NOT_ALLOC_YET,
		ARRAY_ALLOC_ALREADY
	};

	class Fibonacci
	{
	public :

		Fibonacci() = default;
		~Fibonacci();

		// Brute-Force �ϰ� ��� �Լ��� ȣ���ϴ� ���.
		int64_t Fibonacci_By_Recursion(int aimNumber);

		// Dynamic Programming
		int64_t Fibonacci_Top_Down_Init(int aimNumber);

		int64_t Fibonacci_Botton_Up(int aimNumber);

	private :

		int64_t Fibonacci_Top_Down_Recur(int aimNumber);

		FIBONACCI_RESULT array_Initialize(const int size);
		FIBONACCI_RESULT array_Release();

	private :

		int64_t * _resultMemo = nullptr;

	};
}