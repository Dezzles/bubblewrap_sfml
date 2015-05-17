#include "Bubblewrap/Render/SfmlImage.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/SfmlPhysFsInputStream.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		SfmlImage::SfmlImage()
		{
		}

		void SfmlImage::Initialise( Json::Value Params )
		{
			Image::Initialise( Params );
			Stream_.open( Filename_ );
			LoadedImage_.loadFromStream( Stream_ );
		}


		void SfmlImage::Copy( SfmlImage* Target, SfmlImage* Base )
		{
			Image::Copy( Target, Base );
		}

		Colour SfmlImage::GetColour( int X, int Y )
		{
			sf::Vector2u size = LoadedImage_.getSize();
			if ( ( 0 <= X ) && ( X < ( int ) size.x ) && ( 0 <= Y ) && ( Y < ( int ) size.y ) )
			{
				sf::Color colour = LoadedImage_.getPixel( X, Y );
				return Colour( colour.r, colour.g, colour.b, colour.a ); 
			}
			return Colour( 0.0f, 0 , 0 );
		}

		int SfmlImage::GetWidth()
		{
			return LoadedImage_.getSize().x;
		}

		int SfmlImage::GetHeight()
		{
			return LoadedImage_.getSize().y;
		}
	}
}