project "GLFW"
    kind "StaticLib"
    language "C"
    targetdir "../lib/"
    staticruntime "off"

    files 
    {
        "Vendor/glfw/src/**.h", "Vendor/glfw/src/**.c",
    }

    includedirs
    {
        "Vendor/glfw/include"
    }

    targetdir ("../lib/")
    objdir ("../lib/%{prj.name}")

    filter "system:windows"
        systemversion "latest"
        defines { }

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