#ifndef BUBBLEWRAP_SFML_SOUNDBUFFER_HPP
#define BUBBLEWRAP_SFML_SOUNDBUFFER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Audio/SoundBuffer.hpp"
#include "SFML/Audio.hpp"
namespace Bubblewrap
{
	namespace Audio
	{
		class SfmlSoundBuffer :
			public SoundBuffer
		{
		public:
			SfmlSoundBuffer();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SfmlSoundBuffer );

			void Update( float dt );
			virtual void OnAttach();

			sf::SoundBuffer* GetBuffer();
		protected:
			sf::SoundBuffer Buffer_;
		};

	}
}


#endif