#pragma once
#include "Hitobject.h"

namespace BeatmapReader {
	class SliderTick : RelevantObject
	{
	};

	class Slider : RelevantObject
	{
	private:
		Hitobject m_SliderHead;
		Hitobject m_SliderEnd;

		double m_Duration;

		virtual std::string getType() = 0;
	};
}