#ifndef BUBBLEWRAP_SFML_GRAPHICS_REGISTER_HPP
#define BUBBLEWRAP_SFML_GRAPHICS_REGISTER_HPP

namespace Bubblewrap
{
	namespace Registers
	{
		/*! Contains the registration functions for SFML based objects */
		class SfmlRegisters
		{
		public:
			/*! Registers utility objects. This function registers implementations of the following objects:
			- Clock
			\param ObjectRegister Pointer to the ObjectRegister that we want to register on
			*/
			static void RegisterUtilities( void* ObjectRegister );
			
			/*! Registers graphcis objects. This function registers implementations of the following objects:
			- Sprite
			- Texture
			- Vertices
			- Font
			- Text
			\param ObjectRegister Pointer to the ObjectRegister that we want to register on
			*/
			static void RegisterGraphics( void* ObjectRegister );
			
			/*! Registers Audio objects. This function registers implementations of the following objects:
			- Sound
			- SoundBuffer
			- Music
			\param ObjectRegister Pointer to the ObjectRegister that we want to register on
			*/
			static void RegisterAudio( void* ObjectRegister );
		};

	}

}

#endif