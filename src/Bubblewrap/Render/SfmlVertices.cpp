#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/SfmlVertices.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Math/Vector2.hpp"
#include "Bubblewrap/Base/Entity.hpp"
#include "SFML/Graphics.hpp"
#include "Bubblewrap/Render/SfmlTexture.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		SfmlVertices::SfmlVertices()
		{
			VertexCount_ = 0;
			ReservedCount_ = 0;
			SFReservedCount_ = 0;
			SFTexture_ = nullptr;
			Vertices_ = new Vertex[ 0 ];
			Dirty_ = false;
		}


		SfmlVertices::~SfmlVertices()
		{
			delete Vertices_;
		}

		void SfmlVertices::Initialise( Json::Value Params )
		{
			Vertices::Initialise( Params );
		}

		void SfmlVertices::Copy( SfmlVertices* Target, SfmlVertices* Base )
		{
			Vertices::Copy( Target, Base );
			Target->Refresh();
		}

		void SfmlVertices::OnAttach()
		{
			SFTexture_ = dynamic_cast<SfmlTexture*>( Texture_ );
		}

		void SfmlVertices::Update( float dt )
		{
			Vertices::Update( dt );
			assert( !Dirty_ );
			if ( ( Window_ == nullptr ) && ( WindowName_ != "" ) )
			{
				Window_ = GetManager().GetWindowManager().GetItem( WindowName_ );
			}
			Refresh();

		}

		void SfmlVertices::Draw()
		{
			sf::RenderWindow* rw = Window_->GetWindow<sf::RenderWindow>();
			sf::PrimitiveType PrimitiveType = sf::PrimitiveType::Points;
			switch ( PrimitiveType_ )
			{
			case Primitives::Lines:
				PrimitiveType = sf::PrimitiveType::Lines;
				break;
			case Primitives::LinesStrip:
				PrimitiveType = sf::PrimitiveType::LinesStrip;
				break;
			case Primitives::Points:
				PrimitiveType = sf::PrimitiveType::Points;
				break;
			case Primitives::Quads:
				PrimitiveType = sf::PrimitiveType::Quads;
				break;
			case Primitives::Triangles:
				PrimitiveType = sf::PrimitiveType::Triangles;
				break;
			case Primitives::TrianglesStrip:
				PrimitiveType = sf::PrimitiveType::TrianglesStrip;
				break;
			case Primitives::TrianglesFan:
				PrimitiveType = sf::PrimitiveType::TrianglesFan;
				break;
			}
			
			sf::Transform transform;
			auto pos = GetParentEntity()->WorldPosition();
			transform.translate( pos.X(), pos.Y() );
			sf::RenderStates states;
			states.transform = transform;
			SFVertices_.setPrimitiveType( PrimitiveType );
			if ( Texture_ != nullptr )
				states.texture = SFTexture_->GetTexture();/**/
			rw->draw( SFVertices_, states );

		}

		void SfmlVertices::Refresh()
		{ 
			SFVertices_.clear();
			SFVertices_.resize( VertexCount_ );
			float wid = 0;
			float hei = 0;
			if ( Texture_ != nullptr )
			{
				if ( SFTexture_ == nullptr )
				{
					SFTexture_ = dynamic_cast< SfmlTexture* >( Texture_ );
				}
				if ( SFTexture_ != nullptr )
				{
					sf::Vector2u dimensions = SFTexture_->GetTexture()->getSize();
					wid = ( float )SFTexture_->GetTexture()->getSize().x;
					hei = ( float ) SFTexture_->GetTexture()->getSize().y;
				}
			}
			for ( unsigned int Idx = 0; Idx < VertexCount_; ++Idx )
			{
				SFVertices_[ Idx ].color = sf::Color( Vertices_[ Idx ].Colour_.R(), Vertices_[ Idx ].Colour_.G(), Vertices_[ Idx ].Colour_.B(), Vertices_[ Idx ].Colour_.A() );
				SFVertices_[ Idx ].position = sf::Vector2f( Vertices_[ Idx ].Position_.X(), Vertices_[ Idx ].Position_.Y() );

				SFVertices_[ Idx ].texCoords = sf::Vector2f( Vertices_[ Idx ].TexCoords_.X() * wid, Vertices_[ Idx ].TexCoords_.Y() * hei );
			}
			Dirty_ = false;
		}
	}
}