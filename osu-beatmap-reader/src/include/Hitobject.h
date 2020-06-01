#pragma once
#include "RelevantObject.h"

namespace BeatmapReader {
	class Hitobject : public RelevantObject
	{
	public:
		Hitobject()
		{
			m_Time = 0;
			m_Type = 0;
			m_X = 0;
			m_Y = 0;
		}

		std::string getType()
		{
			if (m_Type == 0) return "Hitcircle";
			else if (m_Type == 1) return "Slider";
			else if (m_Type == 3) return "Spinner";
			else return "Invalid";
		}
	};
}