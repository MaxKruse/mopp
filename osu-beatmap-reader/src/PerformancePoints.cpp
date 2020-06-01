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
				std::vector<int> timeDeltas;
				if (j + i >= objects.size())
				{
					Overflow = true;
					break;
				}

				// Get Deltas
				int deltaX, deltaY, deltaTime;

				if (j < 1 || i < 1)
				{
					deltaX = 0;
					deltaY = 0;
					deltaTime = 250;
				}
				else
				{
					deltaX = objects.at(i + j).GetX() - objects.at(i + j - 1).GetX();
					deltaY = objects.at(i + j).GetY() - objects.at(i + j - 1).GetY();
					deltaTime = objects.at(i + j).GetTime() - objects.at(i + j - 1).GetTime();
				}

				timeDeltas.push_back(deltaTime);

				// Calculate Aim Value
				tempAim += 1.0 / std::sqrt(
					std::pow(deltaX, 2) +
					std::pow(deltaY, 2)
				);

				// Calculate Speed Value
				tempSpeed += 1.0 / std::abs(deltaTime);

				// Calculate Strain/Difficulty value

				if (timeDeltas.size() == stepsize)
				{
					long sum = 0;
					for (const auto& delta : timeDeltas)
					{
						sum += delta;
					}

					auto r = sum / timeDeltas.size();

					tempDifficulty += 1.0 / (166.666666 / r * timeDeltas.size());
				}
			}

			// Add Calculated Values to PP

			// Make sure we dont divide by 0
			if (tempAim <= 0)
			{
				tempAim = 1;
			}
			if (tempSpeed <= 0)
			{
				tempSpeed = 1;
			}
			if (tempDifficulty <= 0)
			{
				tempDifficulty = 1;
			}
			if (tempConsistency <= 0)
			{
				tempConsistency = 1;
			}

			Aim += 1.0 / tempAim * stepsize;
			Speed += 1.0 / tempSpeed * stepsize;
			Difficulty += 1.0 / tempDifficulty * stepsize;
			Consistency += 1.0 / tempConsistency * stepsize;

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