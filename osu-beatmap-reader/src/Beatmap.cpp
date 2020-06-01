#include "pch.h"
#include "Beatmap.h"

namespace BeatmapReader {
	Beatmap::Beatmap(const std::string& path)
	{
	}

	std::vector<RelevantObject> Beatmap::GetObjects()
	{
		return m_RelevantObjects;
	}
}