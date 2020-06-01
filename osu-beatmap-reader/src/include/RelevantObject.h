#pragma once

namespace BeatmapReader {
	class RelevantObject
	{
	protected:
		long m_Time{ 0 };
		int m_X{ 0 };
		int m_Y{ 0 };
		int m_Type{ -1 };
	public:
		virtual int GetX() { return m_X; }
		virtual int GetY() { return m_Y; }
		virtual long GetTime() { return m_Time; }
	};
}