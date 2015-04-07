#ifndef BUBBLEWRAP_SFML_MUSIC_HPP
#define BUBBLEWRAP_SFML_MUSIC_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Audio/Music.hpp"
#include "SFML/Audio.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		class SfmlMusic :
			public Music
		{
		public:
			SfmlMusic();
			void Initialise( Json::Value Params );
			CREATE_REGISTER_OVERRIDE( SfmlMusic, Music );

			void Update( float dt );
			virtual void OnAttach( );
			virtual void Play();
			virtual void Pause();
			virtual void Stop();
			virtual Sound::Status GetStatus();
		private:
			sf::Music Music_;
		};

	}
}


#endif