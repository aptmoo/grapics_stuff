project "glfw"
    -- Input
    files
    {
        "./glfw/**.h",
        "./glfw/src/**.c"
    }

    -- Linker
    links { }

    -- Preprocessor
    filter "system:linux"
        defines { "_GLFW_X11" }

    -- filter "system:windows"
    --     defines { "_GLFW_WIN32" }

    -- Language
    language "C"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
  
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "sokol"
    -- Input
    files
    {
        "./sokol/**.h",
        "./sokol/**.c"
    }

    -- Linker
    links { }   -- No links

    filter "system:linux"
        links { "GL", "m", "dl" }

    -- Preprocessor

    -- Language
    language "C"
    cdialect "C11"

    -- Output
    kind        "StaticLib"
    targetdir   "%{wks.location}/lib/"
    objdir      "%{wks.location}/bin-int/"

    -- Configs
    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
    
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"