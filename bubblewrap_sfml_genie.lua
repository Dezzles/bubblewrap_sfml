dofile( "sfml_genie.lua" )

PsyProjectEngineLib( "sfml" )
	files 
	{ 
		"include/**.h", 
		"include/**.hpp", 
		"src/**.cpp" 
	}
	includedirs { 
		"./include", 
		"../bubblewrap/External",
		"../bubblewrap/include/",
		"SFML/include"
		}
	PsyAddEngineLinks {
		"base"
	}
	
	PsyAddExternalLinks {
		"physfs",
		"json",
		"sfml",
	}
