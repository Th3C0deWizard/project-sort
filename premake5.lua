-- premake5.lua
workspace("project-sort")
configurations({ "Debug", "Release" })

project("project-sort")
kind("ConsoleApp")
language("C++")
targetdir("bin/%{cfg.buildcfg}")

files({ "include/**.hpp", "src/**.hpp", "src/**.cpp" })

filter("configurations:Debug")
defines({ "DEBUG" })
symbols("On")

filter("configurations:Release")
defines({ "NDEBUG" })
optimize("On")
