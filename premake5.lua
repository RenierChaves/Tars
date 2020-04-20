workspace "Tars"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Tars/vendor/GLFW/include"

include "Tars/vendor/GLFW"

project "Tars"
	location "Tars"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tarspch.h"
	pchsource "Tars/src/tarspch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"TARS_PLATFORM_WINDOWS",
			"TARS_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "TARS_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "TARS_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "TARS_DIST"
			optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"Tars/vendor/spdlog/include",
		"Tars/src"
	}

	links{
		"Tars"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"TARS_PLATFORM_WINDOWS",
		}

		filter "configurations:Debug"
			defines "TARS_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "TARS_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "TARS_DIST"
			optimize "On"
