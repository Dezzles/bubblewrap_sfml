#include "Bubblewrap/Render/SfmlText.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Render/SfmlFont.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		SfmlText::SfmlText()
		{
		}

		void SfmlText::Initialise( Json::Value Params )
		{
			Text::Initialise( Params );
		}


		void SfmlText::Copy( SfmlText* Target, SfmlText* Base )
		{
			Text::Copy( Target, Base );
		}

		void SfmlText::OnAttach()
		{
			Text::OnAttach();
		}

		void SfmlText::Update( float dt )
		{
			Text::Update( dt );
			if ( IsDirty_ )
			{
				RenderText_.setColor( sf::Color( GetColour().R(), GetColour().G(), GetColour().B(), GetColour().A() ) );
				if ( Font_ != nullptr )
				{
					RenderText_.setFont( ( ( ( SfmlFont* ) Font_ )->GetSfmlFont() ) );
				}
				RenderText_.setString( Text_ );
				RenderText_.setCharacterSize( CharacterSize_ );
				IsDirty_ = false;
			}
			auto pos = GetParentEntity()->WorldPosition() + GetPosition();
			RenderText_.setPosition( pos.X(), pos.Y() );
		}

		void SfmlText::Draw()
		{
			Window_->GetWindow<sf::RenderWindow>()->draw(RenderText_);
		}

	}
}