project "Bubblewrap_SFML"
	kind "staticlib"
	language "C++"
	files { "include/**.h", "include/**.hpp", "src/**.cpp" }
	location "../build/bubblewrap/"
	includedirs { 
		"./include", 
		SFML2DIR .. "/include/",
		"../bubblewrap/External",
		"../bubblewrap/include/"
		}
	links { 
		"External_Json"
	}
	configuration "Debug"
		targetdir ( "../build/lib/debug" )
		defines { "DEBUG" }
		flags { "Symbols" }

	configuration "Release"
		targetdir ( "../build/lib/release" )
		defines { "NDEBUG" }
		flags { "Optimize" }