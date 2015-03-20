#include "Bubblewrap/Base/SfmlClock.hpp"

namespace Bubblewrap
{
	namespace Base
	{
		Time SfmlClock::GetElapsedTime()
		{
			return Time(Clock_.getElapsedTime().asSeconds());
		}

		void SfmlClock::Copy( SfmlClock* Target, SfmlClock* Base )
		{

		}

		void SfmlClock::Update( float dt )
		{

		}
	}
}
