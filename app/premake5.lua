project "app"
    -- Input
    files
    {
        "./src/**.h",
        "./src/**.cpp"
    }

    filter "system:linux"
        files { "./platform/linux/**.h", "./platform/linux/**.cpp", "./platform/sokol/**.h", "./platform/sokol/**.cpp" }

    includedirs
    {
        "%{wks.location}/ext/glfw/include",
        "%{wks.location}/ext/sokol/"
    }

    -- Linker
    links { "sokol", "glfw" }

    filter "system:linux"
        links { "GL", "m", "dl" }

    -- Preprocessor
    defines { "GLFW_INCLUDE_NONE" }

    -- Language
    language "C++"
    cppdialect "C++17"

    -- Output
    kind        "ConsoleApp"
    targetname  "app.out"
    targetdir   "%{wks.location}/bin/"
    objdir      "%{wks.location}/bin-int/"

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"