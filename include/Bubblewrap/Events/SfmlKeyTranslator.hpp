#ifndef BUBBLEWRAP_SFMLKEYTRANSLATOR_HPP
#define BUBBLEWRAP_SFMLKEYTRANSLATOR_HPP

#include "SFML/Window/Keyboard.hpp"
#include "Bubblewrap/Events/EventKeyInput.hpp"

namespace Bubblewrap
{
	namespace Events
	{
		/*! Translates an sf::Keyboard::Key into a Bubblewrap::Events::Key
		\param key SFML keycode
		\returns The corresponding Bubblewrap keycode 
		*/
		Key TranslateKey( sf::Keyboard::Key key );
	}

}

#endif