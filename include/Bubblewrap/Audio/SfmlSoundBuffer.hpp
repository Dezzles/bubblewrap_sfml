#ifndef BUBBLEWRAP_SFML_AUDIO_SFMLSOUNDBUFFER_HPP
#define BUBBLEWRAP_SFML_AUDIO_SFMLSOUNDBUFFER_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Audio/SoundBuffer.hpp"
#include "SFML/Audio.hpp"
namespace Bubblewrap
{
	namespace Audio
	{
		/*! An implementation of SoundBuffer using SFML's sf::SoundBuffer */
		class SfmlSoundBuffer :
			public SoundBuffer
		{
		public:
			SfmlSoundBuffer();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SfmlSoundBuffer );

			void Update( float dt );
			virtual void OnAttach();

			/*! Gets the sf::SoundBuffer stored in this instance of SoundBuffer
			\returns an sf::SoundBuffer object
			*/
			sf::SoundBuffer* GetBuffer();
		protected:
			/*! Sound buffer used for storing sound data */
			sf::SoundBuffer Buffer_;
		};

	}
}


#endif