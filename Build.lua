-- premake5.lua
workspace "GraphicsDev"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}"

group "Core"
	include "Core/Build-Core.lua"
group ""

group "Dependencies"
   include "Core/Build-CoreDeps.lua"
group ""

include "Sandbox/Build-Sandbox.lua"