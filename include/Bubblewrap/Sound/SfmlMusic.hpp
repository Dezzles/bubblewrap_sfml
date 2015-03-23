#ifndef BUBBLEWRAP_SFML_MUSIC_HPP
#define BUBBLEWRAP_SFML_MUSIC_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Sound/Music.hpp"

namespace Bubblewrap
{
	namespace Sound
	{
		class SfmlMusic :
			public Music
		{
		public:
			SfmlMusic();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SfmlMusic );

			void Update( float dt );

		};

	}
}


#endif