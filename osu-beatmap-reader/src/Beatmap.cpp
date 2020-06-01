#include "pch.h"
#include "Beatmap.h"

namespace BeatmapReader {
	Beatmap::Beatmap(const std::string& path)
	{
		// TODO: Beatmap Parser

		// TODO: Convert Sliderticks and sliderends into RelevantObjects and add them to m_RelevantObjects
	}

	std::vector<RelevantObject> Beatmap::GetObjects()
	{
		return m_RelevantObjects;
	}
}