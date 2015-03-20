#include "Bubblewrap/Render/SfmlSprite.hpp"
#include "Bubblewrap/Render/SfmlTexture.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "Bubblewrap/Base/Base.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		SfmlSprite::SfmlSprite()
		{
			Texture_ = nullptr;
		}

		void SfmlSprite::Initialise( Json::Value Params )
		{
			SetWindow( Params[ "window" ].asString() );
			SetSize( Math::Vector2f( Params[ "size" ][ "x" ].asFloat(), Params[ "size" ][ "y" ].asFloat() ) );
			TextureName_ = "";
			if ( !Params[ "texture" ].isNull() )
				TextureName_ = Params[ "texture" ].asString();
		}


		void SfmlSprite::Copy( SfmlSprite* Target, SfmlSprite* Base )
		{
			Drawable::Copy( Target, Base );
			Target->SetSize( Base->Size_ );
			Target->TextureName_ = Base->TextureName_;
			Target->Texture_ = Base->Texture_;
			Target->SetColour( Base->Colour_ );

		}

		void SfmlSprite::OnAttach()
		{
			if ( TextureName_ != "" )
			{
				auto values = GetParentEntity()->GetComponentsByType<Texture>( TextureName_ );

				if ( values.size() > 0 )
				{
					SetTexture( values[ 0 ] );
				}
			}
		}


		void SfmlSprite::Update( float dt )
		{
			Math::Vector2f Position = GetParentEntity()->WorldPosition();
			if ( IsDirty_ )
			{
				Shape_.setFillColor( sf::Color( Colour_.R(), Colour_.G(), Colour_.B(), Colour_.A() ) );
				Shape_.setSize(sf::Vector2f(Size_.X(), Size_.Y()));
				Shape_.setOrigin( Size_.X() * 0.5f, Size_.Y() * 0.5f );
				if ( Texture_ != nullptr )
					Shape_.setTexture( ((SfmlTexture*)Texture_)->GetTexture() );

			}
			Shape_.setPosition(Position.X(), Position.Y());
			Window_->GetWindow<sf::RenderWindow>()->draw( Shape_ );
		}

	}
}