#ifndef BUBBLEWRAP_SFML_FONT_HPP
#define BUBBLEWRAP_SFML_FONT_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Font.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"

#include "SFML/Graphics.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		/*! An implementation of Font using SFML's sf::Font 
		*/
		class SfmlFont
			: public Font
		{
		public:
			SfmlFont();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( SfmlFont, Font );

			virtual void Update( float dt );
			virtual void OnAttach();
			/*! Gets the font data currently stored in Font_
			\return THE sf::Font object stored in this object
			*/
			sf::Font& GetSfmlFont();
		protected:
			/*! Storage class for the font data
			*/
			sf::Font Font_;
		};
	}
}




#endif