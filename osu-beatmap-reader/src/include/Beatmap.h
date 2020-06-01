#pragma once
#include "../pch.h"

namespace BeatmapReader {
	struct General {
		std::vector<RelevantObject> m_Objects;
		std::string m_AudioFileName;
		long m_AudioLeadIn;
		long m_PreviewTime;
		char Countdown;
		std::string m_SampleSet;
		float m_StackLeniency;
		char m_Mode;
	};

	struct Metadata {
		std::string m_Title;
		std::string m_TitleUnicode;
		std::string m_Artist;
		std::string m_ArtistUnicode;
		std::string m_Creator;
		std::string m_Version;
		std::string m_Source;
		std::string m_Tags;
		long m_BeatmapID;
		long m_BeatmapSetID;
	};

	struct Difficulty {
		float m_HPDrainRate;
		float m_CircleSize;
		float m_OverallDifficulty;
		float m_ApproachRate;
		float m_SliderMultiplier;
		float m_SliderTickRate;
	};

	class Beatmap
	{
	private:
		std::vector<RelevantObject> m_RelevantObjects;

	public:
		Beatmap(const std::string& path);

		double GetStarRating();
		std::vector<RelevantObject> GetObjects();
	};
}