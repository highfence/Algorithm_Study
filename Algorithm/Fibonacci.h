#pragma once
#include <vector>

namespace DynamicProgramming
{
	enum class FIBONACCI_RESULT : int
	{
		NONE,
		INVALID_INPUT,
		ARRAY_NOT_ALLOC_YET,
		ARRAY_ALLOC_ALREADY
	};

	class Node_t
	{
	public :

		Node_t() {};
		~Node_t() {};

		int index = -1;
		std::vector<Node_t*> callNodeList;
		std::vector<Node_t*>::size_type GetCallNodeSize() const { return callNodeList.size(); }

		int result = -1;
	};

	class Fibonacci
	{
	public :

		Fibonacci() = default;
		~Fibonacci();

		// Brute-Force 하게 재귀 함수를 호출하는 방법.
		static int64_t Fibonacci_By_Recursion(int aimNumber);

		// Dynamic Programming
		int64_t Fibonacci_Top_Down_Init(int aimNumber);

		int64_t Fibonacci_Botton_Up(int aimNumber);

		// Topological Sort
		int64_t Fibonacci_Topological_Sort(int aimNumber);

	private :

		int64_t Fibonacci_Top_Down_Recur(int aimNumber);

		FIBONACCI_RESULT array_Initialize(const int size);
		FIBONACCI_RESULT array_Release();

	private :

		int64_t * _resultMemo = nullptr;

	};
}