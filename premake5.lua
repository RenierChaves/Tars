workspace "Tars"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Tars"
	location "Tars"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
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

project "Sandbox"
	location "Sandbox"
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
