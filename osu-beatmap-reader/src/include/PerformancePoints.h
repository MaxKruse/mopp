#pragma once
#include "../pch.h"

namespace BeatmapReader {
	struct PP
	{
		double AimPP;
		double SpeedPP;
		double DifficultyPP;
		double ConsistencyPP;
		double TotalPP;
	};

	class PerformancePoints
	{
	private:
		PP m_PP;
	public:
		PerformancePoints(std::vector<RelevantObject>& objects);
		PP GetPP();
	};
}