#ifndef BUBBLEWRAP_SFMLKEYTRANSLATOR_HPP
#define BUBBLEWRAP_SFMLKEYTRANSLATOR_HPP

#include "SFML/Window/Keyboard.hpp"
#include "Bubblewrap/Events/EventKeyInput.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		Key TranslateKey( sf::Keyboard::Key key );
	}

}

#endif