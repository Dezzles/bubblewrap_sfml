table.insert( additionalExternalLibraries, "sfml" )

if PsyProjectExternalLib( "sfml", "C++" ) then
	defines { "SFML_STATIC" , "SFML_SYSTEM_EXPORTS" }
	configuration "*"
		kind ( EXTERNAL_PROJECT_KIND )
		includedirs {
			"SFML/include",
			"SFML/src",
			"SFML/extlibs/headers/AL",
			"SFML/extlibs/headers/freetype2",
			"SFML/extlibs/headers/jpeg",
			"SFML/extlibs/headers/ogg",
			"SFML/extlibs/headers/stb_image",
			"SFML/extlibs/headers/vorbis",
			"SFML/extlibs/headers",
		}
		files {
			"SFML/src/SFML/Audio/ALCheck.cpp",
			"SFML/src/SFML/Audio/AlResource.cpp",
			"SFML/src/SFML/Audio/AudioDevice.cpp",
			"SFML/src/SFML/Audio/Listener.cpp",
			"SFML/src/SFML/Audio/Music.cpp",
			"SFML/src/SFML/Audio/Sound.cpp",
			"SFML/src/SFML/Audio/SoundBuffer.cpp",
			"SFML/src/SFML/Audio/SoundBufferRecorder.cpp",
			"SFML/src/SFML/Audio/InputSoundFile.cpp",
			"SFML/src/SFML/Audio/OutputSoundFile.cpp",
			"SFML/src/SFML/Audio/SoundRecorder.cpp",
			"SFML/src/SFML/Audio/SoundSource.cpp",
			"SFML/src/SFML/Audio/SoundStream.cpp",
			"SFML/src/SFML/Audio/SoundFileFactory.cpp",
			"SFML/src/SFML/Audio/SoundFileReaderFlac.cpp",
			"SFML/src/SFML/Audio/SoundFileReaderOgg.cpp",
			"SFML/src/SFML/Audio/SoundFileReaderWav.cpp",
			"SFML/src/SFML/Audio/SoundFileWriterFlac.cpp",
			"SFML/src/SFML/Audio/SoundFileWriterOgg.cpp",
			"SFML/src/SFML/Audio/SoundFileWriterWav.cpp",
			"SFML/src/SFML/Graphics/BlendMode.cpp",
			"SFML/src/SFML/Graphics/Color.cpp",
			"SFML/src/SFML/Graphics/Font.cpp",
			"SFML/src/SFML/Graphics/GLCheck.cpp",
			"SFML/src/SFML/Graphics/GLExtensions.cpp",
			"SFML/src/SFML/Graphics/Image.cpp",
			"SFML/src/SFML/Graphics/ImageLoader.cpp",
			"SFML/src/SFML/Graphics/RenderStates.cpp",
			"SFML/src/SFML/Graphics/RenderTexture.cpp",
			"SFML/src/SFML/Graphics/RenderTarget.cpp",
			"SFML/src/SFML/Graphics/RenderWindow.cpp",
			"SFML/src/SFML/Graphics/Shader.cpp",
			"SFML/src/SFML/Graphics/Texture.cpp",
			"SFML/src/SFML/Graphics/TextureSaver.cpp",
			"SFML/src/SFML/Graphics/Transform.cpp",
			"SFML/src/SFML/Graphics/Transformable.cpp",
			"SFML/src/SFML/Graphics/View.cpp",
			"SFML/src/SFML/Graphics/Vertex.cpp",
			"SFML/src/SFML/Graphics/Shape.cpp",
			"SFML/src/SFML/Graphics/CircleShape.cpp",
			"SFML/src/SFML/Graphics/RectangleShape.cpp",
			"SFML/src/SFML/Graphics/ConvexShape.cpp",
			"SFML/src/SFML/Graphics/Sprite.cpp",
			"SFML/src/SFML/Graphics/Text.cpp",
			"SFML/src/SFML/Graphics/VertexArray.cpp",
			"SFML/src/SFML/Graphics/RenderTextureImpl.cpp",
			"SFML/src/SFML/Graphics/RenderTextureImplFBO.cpp",
			"SFML/src/SFML/Graphics/RenderTextureImplDefault.cpp",
			"SFML/src/SFML/Network/Ftp.cpp",
			"SFML/src/SFML/Network/Http.cpp",
			"SFML/src/SFML/Network/IpAddress.cpp",
			"SFML/src/SFML/Network/Packet.cpp",
			"SFML/src/SFML/Network/Socket.cpp",
			"SFML/src/SFML/Network/SocketSelector.cpp",
			"SFML/src/SFML/Network/TcpListener.cpp",
			"SFML/src/SFML/Network/TcpSocket.cpp",
			"SFML/src/SFML/Network/UdpSocket.cpp",
			"SFML/include/SFML/System/InputStream.hpp",
			"SFML/src/SFML/System/Clock.cpp",
			"SFML/src/SFML/System/Err.cpp",
			"SFML/src/SFML/System/Lock.cpp",
			"SFML/src/SFML/System/Mutex.cpp",
			"SFML/src/SFML/System/Sleep.cpp",
			"SFML/src/SFML/System/String.cpp",
			"SFML/src/SFML/System/Thread.cpp",
			"SFML/src/SFML/System/ThreadLocal.cpp",
			"SFML/src/SFML/System/Time.cpp",
			"SFML/src/SFML/System/FileInputStream.cpp",
			"SFML/src/SFML/System/MemoryInputStream.cpp",
			"SFML/src/SFML/Window/Context.cpp",
			"SFML/src/SFML/Window/GlContext.cpp",
			"SFML/src/SFML/Window/GlResource.cpp",
			"SFML/src/SFML/Window/Joystick.cpp",
			"SFML/src/SFML/Window/JoystickManager.cpp",
			"SFML/src/SFML/Window/Keyboard.cpp",
			"SFML/src/SFML/Window/Mouse.cpp",
			"SFML/src/SFML/Window/Touch.cpp",
			"SFML/src/SFML/Window/Sensor.cpp",
			"SFML/src/SFML/Window/SensorManager.cpp",
			"SFML/src/SFML/Window/VideoMode.cpp",
			"SFML/src/SFML/Window/Window.cpp",
			"SFML/src/SFML/Window/WindowImpl.cpp",
		}
	configuration { "vs*" }
		libdirs { "SFML/extlibs/libs-msvc/x86" }
		links { "flac" , "freetype", "jpeg", "ogg", "openal32", "vorbis", "vorbisenc", "vorbisfile", "opengl32" }
		flags
		{
			"Unicode"
		}
		defines
		{
			"UNICODE"
		}
		files
		{
			"SFML/src/SFML/Network/Win32/SocketImpl.cpp",
			"SFML/src/SFML/System/Win32/ClockImpl.cpp",
			"SFML/src/SFML/System/Win32/MutexImpl.cpp",
			"SFML/src/SFML/System/Win32/SleepImpl.cpp",
			"SFML/src/SFML/System/Win32/ThreadImpl.cpp",
			"SFML/src/SFML/System/Win32/ThreadLocalImpl.cpp",
			"SFML/src/SFML/Window/Win32/WglContext.cpp",
			"SFML/src/SFML/Window/Win32/WglExtensions.cpp",
			"SFML/src/SFML/Window/Win32/InputImpl.cpp",
			"SFML/src/SFML/Window/Win32/JoystickImpl.cpp",
			"SFML/src/SFML/Window/Win32/SensorImpl.cpp",
			"SFML/src/SFML/Window/Win32/VideoModeImpl.cpp",
			"SFML/src/SFML/Window/Win32/WindowImplWin32.cpp",
		}

	configuration { "mingw-*" }
		files
		{
			"SFML/src/SFML/Network/Win32/SocketImpl.cpp",
			"SFML/src/SFML/System/Win32/ClockImpl.cpp",
			"SFML/src/SFML/System/Win32/MutexImpl.cpp",
			"SFML/src/SFML/System/Win32/SleepImpl.cpp",
			"SFML/src/SFML/System/Win32/ThreadImpl.cpp",
			"SFML/src/SFML/System/Win32/ThreadLocalImpl.cpp",
			"SFML/src/SFML/Window/Win32/WglContext.cpp",
			"SFML/src/SFML/Window/Win32/WglExtensions.cpp",
			"SFML/src/SFML/Window/Win32/InputImpl.cpp",
			"SFML/src/SFML/Window/Win32/JoystickImpl.cpp",
			"SFML/src/SFML/Window/Win32/SensorImpl.cpp",
			"SFML/src/SFML/Window/Win32/VideoModeImpl.cpp",
			"SFML/src/SFML/Window/Win32/WindowImplWin32.cpp",
		}

	configuration { "android-*" }
		files
		{
			"SFML/src/SFML/System/Android/Activity.cpp",
			"SFML/src/SFML/System/Android/ResourceStream.cpp",
			"SFML/src/SFML/System/Android/ResourceStream.cpp",
			"SFML/src/SFML/Window/Android/WindowImplAndroid.cpp",
			"SFML/src/SFML/Window/Android/VideoModeImpl.cpp",
			"SFML/src/SFML/Window/Android/InputImpl.cpp",
			"SFML/src/SFML/Window/Android/JoystickImpl.cpp",
		}

	configuration { "freebsd" }
		files
		{
			"SFML/src/SFML/System/Unix/ClockImpl.cpp",
			"SFML/src/SFML/System/Unix/MutexImpl.cpp",
			"SFML/src/SFML/System/Unix/SleepImpl.cpp",
			"SFML/src/SFML/System/Unix/ThreadImpl.cpp",
			"SFML/src/SFML/System/Unix/ThreadLocalImpl.cpp",		
			"SFML/src/SFML/Window/Unix/Display.cpp",
			"SFML/src/SFML/Window/Unix/InputImpl.cpp",
			"SFML/src/SFML/Window/Unix/SensorImpl.cpp",
			"SFML/src/SFML/Window/Unix/VideoModeImpl.cpp",
			"SFML/src/SFML/Window/Unix/WindowImplX11.cpp",
			"SFML/src/SFML/Window/FreeBSD/JoystickImpl.cpp",
		}

	configuration { "osx" }
		files
		{
		
		}


end

