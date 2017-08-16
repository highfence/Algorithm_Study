#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

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

	int64_t Fibonacci::Fibonacci_Top_Down_Recur(int aimNumber)
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

	int64_t Fibonacci::Fibonacci_Botton_Up(int aimNumber)
	{
		if (aimNumber <= 0) return aimNumber;

		// 배열 초기화.
		if (array_Initialize(aimNumber + 1) != FIBONACCI_RESULT::NONE)
		{
			return -1;
		}

		_resultMemo[0] = 0;
		_resultMemo[1] = 1;
		
		for (auto i = 2; i <= aimNumber; ++i)
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

	int64_t Fibonacci::Fibonacci_Topological_Sort(int aimNumber)
	{
		// 음수값, 0값 처리.
		if (aimNumber <= 0) return aimNumber;

		// 진입 노드가 0인 노드를 제거하는 방식으로 Topological Sort를 진행할 것이기 때문에,
		// 제거가 쉬운 List로 그래프를 정의.
		// 탐색을 위해서 nodeArray에 node들을 생성시키고, 이를 가리키는 포인터 형태로 그래프를 만든다.
		// 각 배열의 index 인자는 index 값에 해당하는 피보나치 행렬의 subproblem에 해당.
		auto nodeArray = new Node_t[aimNumber + 1];
		auto nodeList = std::list<Node_t*>();

		// 인덱스 초기화 및 그래프 생성.
		for (auto i = 0; i < aimNumber; ++i)
		{
			nodeArray[i].index = i;
			nodeList.push_back(&nodeArray[i]);
		}

		// 호출 관계 연결.
		// index n이 m을 호출하는 경우, m의 callNodeList에 n이 들어간다.
		auto callNodeMaking = [&](Node_t * node)
		{
			if (node == nullptr) return;

			auto nodeIdx = node->index;
			
			for (auto i = 0; i < 2; ++i)
			{
				if (--nodeIdx >= 0)
				{
					nodeArray[nodeIdx].callNodeList.push_back(node);
				}
			}
		};
		for (auto i = 0; i < aimNumber; ++i)
		{
			callNodeMaking(&nodeArray[i]);
		}

		// Topological Sort를 처리되지 않은 노드가 없을 때까지 실행한다.
		while (nodeList.empty())
		{
			// 진입 노드가 0인 노드를 찾는다.
			auto zeroIndegreeNode = std::find_if(nodeList.begin(), nodeList.end(), [&](Node_t * node) { return node->GetCallNodeSize() == 0; });

			// 진입노드가 0인 노드가 없다면 에러.
			if (zeroIndegreeNode == nodeList.end()) break;

			// 진입 노드가 0인 노드의 결과 값을 계산한다.

			// 진입 노드가 들어있는 callNodeList를 찾아 제거해준다.

			// 처리했다고 판단하고 노드 리스트에서 제거한다.
		}

		auto aimValue = nodeArray[aimNumber].result;

		delete[] nodeArray;

		return aimValue;
	}

	FIBONACCI_RESULT Fibonacci::array_Initialize(const int size)
	{
		// 배열이 이미 만들어진 상태라면 에러 반환.
		if (_resultMemo != nullptr)
		{
			return FIBONACCI_RESULT::ARRAY_ALLOC_ALREADY;
		}

		// 만들어진 상황이 아니라면 사이즈만큼 할당.
		_resultMemo = new int64_t[size];
		
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