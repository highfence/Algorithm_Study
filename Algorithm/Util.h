#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

namespace Util
{
	class Timer
	{
	public:

		Timer(void) { Init(); }

		virtual ~Timer(void) {}

		void Start()
		{
			ProcessTime();
		}

		void Check(std::wstring preAnnounce, std::wstring postAnnounce)
		{
			std::wstring debugLabel = preAnnounce + std::to_wstring(GetElapsedTime()) + postAnnounce;
			OutputDebugString(debugLabel.c_str());
		}

	private :

		inline float GetElapsedTime() const
		{
			return m_fElapsedTime;
		};

		void Init()
		{
			LARGE_INTEGER qwTicksPerSec, qwTime;

			m_bUseQPF = (bool)(QueryPerformanceFrequency(
				&qwTicksPerSec) != 0);

			if (!m_bUseQPF)	return;

			m_llQPFTicksPerSec = qwTicksPerSec.QuadPart;

			QueryPerformanceCounter(&qwTime);
			m_llLastElapsedTime = qwTime.QuadPart;
		}

		void ProcessTime()
		{
			if (!m_bUseQPF)
			{
				return;
			}

			LARGE_INTEGER qwTime;
			QueryPerformanceCounter(&qwTime);

			m_fElapsedTime = (float)
				((double)(qwTime.QuadPart - m_llLastElapsedTime)
					/ (double)m_llQPFTicksPerSec);

			m_llLastElapsedTime = qwTime.QuadPart;
		}

	private :

		bool		m_bUseQPF = false;
		float		m_fElapsedTime = 0.0f;
		LONGLONG	m_llQPFTicksPerSec = 0;
		LONGLONG	m_llLastElapsedTime = 0;
	};

}
