#ifndef BUBBLEWRAP_SFML_SOUNDBUFFER_HPP
#define BUBBLEWRAP_SFML_SOUNDBUFFER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Sound/SoundBuffer.hpp"

namespace Bubblewrap
{
	namespace Sound
	{
		class SfmlSoundBuffer :
			public SoundBuffer
		{
		public:
			SfmlSoundBuffer();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SfmlSoundBuffer );

			void Update( float dt );

		};

	}
}


#endif