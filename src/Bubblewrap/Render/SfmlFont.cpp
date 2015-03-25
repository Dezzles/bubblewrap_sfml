#include "Bubblewrap/Render/SfmlFont.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
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

			Font_.loadFromFile( Params[ "fontFile" ].asString() );
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