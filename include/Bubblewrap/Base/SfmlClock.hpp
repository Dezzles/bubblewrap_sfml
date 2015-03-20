#ifndef BUBBLEWRAP_SFML_CLOCK_HPP
#define BUBBLEWRAP_SFML_CLOCK_HPP

#include "Bubblewrap/Base/Clock.hpp"
#include "SFML/System.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		class SfmlClock
			: public Clock
		{
		public:
			CREATE_REGISTER_OVERRIDE( SfmlClock, Clock );

		public:
			Time GetElapsedTime();
			void Update( float dt );

			sf::Clock Clock_;
		};
	}
}


#endif