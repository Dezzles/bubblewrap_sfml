#ifndef BUBBLEWRAP_SFML_SOUND_HPP
#define BUBBLEWRAP_SFML_SOUND_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Sound/Sound.hpp"

namespace Bubblewrap
{
	namespace Sound
	{
		class SfmlSound :
			public Sound
		{
		public:
			SfmlSound();
			void Initialise( Json::Value Params );
			CREATE_REGISTER( SfmlSound );

			void Update( float dt );

		};

	}
}


#endif