workspace "osu-beatmap-reader"
	startproject "mopp"

	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
	}

outputDir = "/%{cfg.system}/%{cfg.architecture}/%{cfg.buildcfg}"

project "osu-beatmap-reader"
	location "osu-beatmap-reader"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	characterset "Unicode"
	vectorextensions "AVX"
	floatingpoint "Fast"

	targetdir ("bin/%{prj.name}" .. outputDir)
	objdir ("bin/%{prj.name}/intermediates" .. outputDir)

	pchheader "pch.h"
	pchsource "osu-beatmap-reader/src/pch.cpp"

	files
	{
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/src/include/**.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src/include",
	}

	defines
	{
		""
	}

	flags
	{
		"MultiProcessorCompile"
	}

	links
	{
		
	}
	
	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		optimize "Debug"
		symbols "Full"

	filter "configurations:Release"
		optimize "Speed"
		symbols "Off"

project "mopp"
	location "mopp"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "On"
	characterset "Unicode"
	vectorextensions "AVX"
	floatingpoint "Fast"

	targetdir ("bin/%{prj.name}" .. outputDir)
	objdir ("bin/%{prj.name}/intermediates" .. outputDir)

	pchheader "pch.h"
	pchsource "mopp/src/pch.cpp"

	files
	{
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.h",
		"%{prj.name}/src/include/**.h",
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src/include",
		"osu-beatmap-reader/src/include",
	}

	defines
	{
		""
	}

	flags
	{
		"MultiProcessorCompile"
	}

	links
	{
		"osu-beatmap-reader"
	}
	
	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		optimize "Debug"
		symbols "Full"

	filter "configurations:Release"
		optimize "Speed"
		symbols "Off"