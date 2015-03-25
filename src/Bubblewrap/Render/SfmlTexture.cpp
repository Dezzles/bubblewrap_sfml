#include "Bubblewrap/Render/SfmlTexture.hpp"
#include "Bubblewrap/Render/Texture.hpp"

namespace Bubblewrap
{
	namespace Render
	{
		SfmlTexture::SfmlTexture()
		{

		}

		void SfmlTexture::Initialise( Json::Value Params )
		{
			Texture::Initialise( Params );
			Texture_.loadFromFile( Params[ "texture" ].asString() );
			
		}

		void SfmlTexture::Copy( SfmlTexture* Target, SfmlTexture* Base )
		{
			Texture::CopyDef(Target, Base);
			Target->Texture_ = Base->Texture_;
		}

		void SfmlTexture::Update( float dt )
		{
		}

		sf::Texture* SfmlTexture::GetTexture()
		{
			return &Texture_;
		}
	}
}