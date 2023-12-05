project "Core"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    files 
    {
        "Source/**.h", "Source/**.cpp",
        "Platform/generic/**.h", "Platform/generic/**.cpp",  -- This should hopefully compile everywhere.
    }

    includedirs
    {
        "Source",
        "Platfom",
        "Vendor",
    }

    links
    {
        "GLFW"
    }

    targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

    filter "system:windows"
        systemversion "latest"
        defines { "CORE_WINDOWS" }

    filter "system:linux"
        systemversion "latest"
        defines { "CORE_LINUX" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"