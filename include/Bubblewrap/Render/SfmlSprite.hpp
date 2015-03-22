#ifndef BUBBLEWRAP_SFML_SPRITE_HPP
#define BUBBLEWRAP_SFML_SPRITE_HPP

#include "SFML/Graphics.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Render/Sprite.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Render/Colour.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "Bubblewrap/Render/Texture.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		class SfmlSprite
			: public Sprite
		{
		public:
			SfmlSprite();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( SfmlSprite, Sprite );

			virtual void Update( float dt );
			virtual void OnAttach();

		private:

			sf::RectangleShape Shape_;
		};
	}
}


#endif