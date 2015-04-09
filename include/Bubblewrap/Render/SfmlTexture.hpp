#ifndef BUBBLEWRAP_SFML_TEXTURE_H
#define BUBBLEWRAP_SFML_TEXTURE_H

#include "SFML/Graphics.hpp"
#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Base/Component.hpp"
#include "Bubblewrap/Render/Texture.hpp"

namespace Bubblewrap
{
	namespace Render
	{

		/*! An implementation of Texture using SFML's sf::Texture */
		class SfmlTexture
			: public Texture
		{
		public:
			SfmlTexture();
			void Initialise(Json::Value Params);

			CREATE_REGISTER_OVERRIDE( SfmlTexture, Texture );

			virtual void Update( float dt );

			/*! Gets the currently stored Texture
			\returns A pointer to an sf::Textre 
			*/
			sf::Texture* GetTexture();
		private:

			sf::Texture Texture_;

		};
	}
}


#endif