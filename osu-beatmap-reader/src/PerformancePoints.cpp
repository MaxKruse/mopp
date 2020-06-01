#include "pch.h"
#include "include/PerformancePoints.h"

namespace BeatmapReader {
	PerformancePoints::PerformancePoints(std::vector<RelevantObject>& objects)
	{
		double Aim = 0;
		double Speed = 0;
		double Difficulty = 0;
		double Consistency = 0;

		size_t stepsize = 7;

		bool Overflow = false;

		double tempAim;
		double tempSpeed;
		double tempDifficulty;
		double tempConsistency;

		for (size_t i = 0; i < objects.size() - 1; i++)
		{
			tempAim = 0;
			tempSpeed = 0;
			tempDifficulty = 0;
			tempConsistency = 0;

			for (size_t j = 0; j < stepsize; j++)
			{
				if (j + i >= objects.size())
				{
					Overflow = true;
					break;
				}

				// Calculate Aim Value
				int deltaX, deltaY;

				if (j < 1 || i < 1)
				{
					deltaX = 0;
					deltaY = 0;
				}
				else
				{
					deltaX = objects.at(i + j).GetX() - objects.at(i + j - 1).GetX();
					deltaY = objects.at(i + j).GetY() - objects.at(i + j - 1).GetY();
				}

				tempAim += std::sqrt(
					deltaX +
					deltaY
				);

				// Calculate Speed Value

				// Calculate Strain/Difficulty value

				// Calculate Consistency in Timing signatures
			}

			// Add Calculated Values to PP

			Aim += 1.0 / tempAim;
			Speed += 1.0 / tempSpeed;
			Difficulty += 1.0 / tempDifficulty;
			Consistency += 1.0 / tempConsistency;

			if (Overflow)
			{
				break;
			}
		}

		m_PP.AimPP = Aim;
		m_PP.SpeedPP = Speed;
		m_PP.ConsistencyPP = Consistency;
		m_PP.DifficultyPP = Difficulty;
		m_PP.TotalPP = 1.0 / (1.0 / m_PP.AimPP + 1.0 / m_PP.SpeedPP + 1.0 / m_PP.DifficultyPP + 1.0 / m_PP.ConsistencyPP) * 4;
	}

	PP PerformancePoints::GetPP()
	{
		return m_PP;
	}
}