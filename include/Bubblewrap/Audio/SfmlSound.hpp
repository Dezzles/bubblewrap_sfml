#ifndef BUBBLEWRAP_SFML_SOUND_HPP
#define BUBBLEWRAP_SFML_SOUND_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Audio/Sound.hpp"
#include "SFML/Audio.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		class SfmlSoundBuffer;
		/*! An implementation of Sound using SFML's sf::Sound */
		class SfmlSound :
			public Sound
		{
		public:
			SfmlSound();
			void Initialise( Json::Value Params );
			CREATE_REGISTER_OVERRIDE( SfmlSound, Sound );

			void Update( float dt );

			void OnAttach();
			virtual void Play();
			virtual void Pause();
			virtual void Stop();
			virtual Status GetStatus();

		private:
			SfmlSoundBuffer* SfBuffer_;
			sf::Sound Sound_;
		};

	}
}


#endif