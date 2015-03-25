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

		class SfmlFont
			: public Font
		{
		public:
			SfmlFont();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( SfmlFont, Font );

			virtual void Update( float dt );
			virtual void OnAttach();
			sf::Font& GetSfmlFont();
		protected:
			sf::Font Font_;
		};
	}
}




#endif