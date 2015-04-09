#ifndef BUBBLEWRAP_SFML_CLOCK_HPP
#define BUBBLEWRAP_SFML_CLOCK_HPP

#include "Bubblewrap/Base/Clock.hpp"
#include "SFML/System.hpp"
namespace Bubblewrap
{
	namespace Base
	{
		/*! An implementation of Clock using SFML's sf::Clock*/
		class SfmlClock
			: public Clock
		{
		public:
			CREATE_REGISTER_OVERRIDE( SfmlClock, Clock );

		public:
			Time GetElapsedTime();
			void Update( float dt );

		private:
			sf::Clock Clock_;
		};
	}
}


#endif