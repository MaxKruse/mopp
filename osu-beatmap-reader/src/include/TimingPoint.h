#pragma once
#include "../pch.h"

namespace BeatmapReader {
	class TimingPoint
	{
		long m_Time;
		float beatLength;
		long m_Meter;
		long m_SampleSet;
		long m_SampleIndex;
		long m_Volume;
		bool m_Uninherited;
	};
}