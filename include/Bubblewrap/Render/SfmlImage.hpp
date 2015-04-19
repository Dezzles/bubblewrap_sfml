#ifndef BUBBLEWRAP_SFML_RENDER_SFMLIMAGE_HPP
#define BUBBLEWRAP_SFML_RENDER_SFMLIMAGE_HPP

#include "Bubblewrap/Render/Image.hpp"
#include "Bubblewrap/Base/SfmlPhysFsInputStream.hpp"
#include <SFML/Graphics.hpp>
namespace Bubblewrap
{
	namespace Render
	{
		class SfmlImage : 
			public Image
		{
			SfmlImage();
		public:
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( SfmlImage, Image );

			Colour GetColour( int X, int Y );

			int GetWidth();
			int GetHeight();

		private:
			sf::Image LoadedImage_;
			Base::SfmlPhysFsInputStream Stream_;
		};
	}
}


#endif