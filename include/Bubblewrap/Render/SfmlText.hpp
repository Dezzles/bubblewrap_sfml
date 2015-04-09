#ifndef BUBBLEWRAP_SFML_TEXT_HPP
#define BUBBLEWRAP_SFML_TEXT_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Render/Text.hpp"
#include "SFML/Graphics.hpp"
namespace Bubblewrap
{
	namespace Render
	{

		/*! An implementation of Text using SFML's sf::Text */
		class SfmlText
			: public Text
		{
		public:
			SfmlText();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( SfmlText, Text );

			virtual void Update( float dt );
			virtual void OnAttach();

			virtual void Draw();
		private:
			sf::Text RenderText_;
		};
	}
}




#endif