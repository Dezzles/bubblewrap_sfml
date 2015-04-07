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
			Math::Vector2f Modifier;
			sf::FloatRect Size = RenderText_.getLocalBounds();
			if ( HorizontalAlignment_ == HAlign::Centre )
			{
				Modifier.SetX( -Size.width * 0.5f );
			}
			else if ( HorizontalAlignment_ == HAlign::Right )
			{
				Modifier.SetX( -Size.width );
			}
			if ( VerticalAlignment_ == VAlign::Centre )
			{
				Modifier.SetY( -Size.height * 0.5f );
			}
			else if ( VerticalAlignment_ == VAlign::Bottom )
			{
				Modifier.SetY( -Size.height );
			}
			auto pos = GetParentEntity()->WorldPosition().XY() + GetPosition() + Modifier;
			RenderText_.setPosition( pos.X(), pos.Y() );
		}

		void SfmlText::Draw()
		{
			Window_->GetWindow<sf::RenderWindow>()->draw(RenderText_);
		}

	}
}