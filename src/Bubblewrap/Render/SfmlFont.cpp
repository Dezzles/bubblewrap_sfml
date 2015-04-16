#include "Bubblewrap/Render/SfmlFont.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Base/SfmlPhysFsInputStream.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		SfmlFont::SfmlFont()
		{
		}

		void SfmlFont::Initialise( Json::Value Params )
		{
			Font::Initialise( Params );
			Stream_.open( Params[ "fontFile" ].asString().c_str() );
			Font_.loadFromStream( Stream_ );
		}


		void SfmlFont::Copy( SfmlFont* Target, SfmlFont* Base )
		{
			Font::Copy( Target, Base );
		}

		void SfmlFont::OnAttach()
		{
		}


		void SfmlFont::Update( float dt )
		{

		}

		sf::Font& SfmlFont::GetSfmlFont()
		{
			return Font_;
		}


	}
}