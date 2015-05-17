PsyProjectEngineLib( "sfml" )
	files 
	{ 
		"include/**.h", 
		"include/**.hpp", 
		"src/**.cpp" 
	}
	includedirs { 
		SFML2DIR .. "/include/",
		"./include", 
		"../bubblewrap/External",
		"../bubblewrap/include/",
		}
	PsyAddEngineLinks {
		"base"
	}
	
	PsyAddExternalLinks {
		"physfs",
		"json",
	}
