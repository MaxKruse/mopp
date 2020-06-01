#include "pch.h"
#include "Beatmap.h"
#include "PerformancePoints.h"
#include "fmt/core.h"

int main(int argc, char** args)
{
	if (argc == 2 && std::filesystem::exists(args[1]))
	{
		auto bm = BeatmapReader::Beatmap(std::string(args[1]));

		auto pp = BeatmapReader::PerformancePoints(bm.GetObjects());
	}
	else
	{
		fmt::print("Please Provide a path to the .osu file");
		return 1;
	}

	return 0;
}