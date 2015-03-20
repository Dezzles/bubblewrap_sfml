#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/SfmlVertices.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Math/Vector.hpp"
#include "SFML/Graphics.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		SfmlVertices::SfmlVertices()
		{
			VertexCount_ = 0;
			ReservedCount_ = 0;
			SFReservedCount_ = 0;

			Vertices_ = new Vertex[ 0 ];
			SFVertices_ = new sf::Vertex[ 0 ];
			Dirty_ = false;
		}


		SfmlVertices::~SfmlVertices()
		{
			delete Vertices_;
			delete SFVertices_;
		}

		void SfmlVertices::Initialise( Json::Value Params )
		{
			Vertices::Initialise( Params );

			SetPrimitiveType( Converts::PrimitiveFromString( Params[ "primitivetype" ].asString() ) );
			Reserve( Params[ "vertices" ].size() );
			int uCount = Params[ "vertices" ].size();
			VertexCount_ = uCount;
			for ( int Idx = 0; Idx < uCount; ++Idx )
			{
				Vertices_[ Idx ].Colour_ = Colour( Params[ "vertices" ][ Idx ][ "colour" ].asString() );
				Vertices_[ Idx ].Position_ = Math::Vector2f( Params[ "vertices" ][ Idx ][ "position" ].asString() );
				Vertices_[ Idx ].Colour_ = Colour( Params[ "vertices" ][ Idx ][ "colour" ].asString() );
			}
		}


		void SfmlVertices::Copy( SfmlVertices* Target, SfmlVertices* Base )
		{
			Drawable::Copy( Target, Base );
			Target->Reserve( Base->VertexCount_ );
			memcpy( Target->Vertices_, Base->Vertices_, Base->VertexCount_ * sizeof( Vertex ) );

			Target->PrimitiveType_ = Base->PrimitiveType_;
			Target->ReservedCount_ = Base->VertexCount_;
			Target->VertexCount_ = Base->VertexCount_;
			Target->Refresh();
		}

		void SfmlVertices::OnAttach()
		{

		}

		void SfmlVertices::Update( float dt )
		{
			assert( !Dirty_ );
			if ( ( Window_ == nullptr ) && ( WindowName_ != "" ) )
			{
				Window_ = GetManager().GetWindowManager().GetItem( WindowName_ );
			}
			if ( Window_ == nullptr )
				return;

			sf::RenderWindow* rw = Window_->GetWindow<sf::RenderWindow>();
			sf::PrimitiveType PrimitiveType;
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
			rw->draw( SFVertices_, VertexCount_, PrimitiveType );
		}

		void SfmlVertices::SetPrimitiveType( Primitives PrimitiveType )
		{
			PrimitiveType_ = PrimitiveType;
		}

		void SfmlVertices::AddVertex( Vertex V )
		{
			if ( VertexCount_ == ReservedCount_ )
			{
				Reserve( 1 );
			}
			Vertices_[ VertexCount_ ] = V;
			++VertexCount_;
			Dirty_ = true;
		}
		void SfmlVertices::Reserve( unsigned int Amount )
		{
			int CurrentCount = ReservedCount_;
			int NewCount = ReservedCount_ + Amount;
			Vertex* newMem = new Vertex[ NewCount ];
			memset( newMem, 0, NewCount * sizeof( Vertex ) );
			memcpy( newMem, Vertices_, CurrentCount * sizeof( Vertex ) );
			delete Vertices_;
			Vertices_ = newMem;
			ReservedCount_ = NewCount;
		}
		void SfmlVertices::SetVertex( unsigned int Idx, Vertex V )
		{
			assert( Idx < VertexCount_ );
			Vertices_[ Idx ] = V;
			Dirty_ = true;
		}

		void SfmlVertices::Refresh()
		{
			if ( SFReservedCount_ < VertexCount_ )
			{
				delete SFVertices_;
				SFVertices_ = new sf::Vertex[ VertexCount_ ];
				SFReservedCount_ = VertexCount_;
			}
			for ( unsigned int Idx = 0; Idx < VertexCount_; ++Idx )
			{
				SFVertices_[ Idx ].color = sf::Color( Vertices_[ Idx ].Colour_.R(), Vertices_[ Idx ].Colour_.G(), Vertices_[ Idx ].Colour_.B(), Vertices_[ Idx ].Colour_.A() );
				SFVertices_[ Idx ].position = sf::Vector2f( Vertices_[ Idx ].Position_.X(), Vertices_[ Idx ].Position_.Y() );
				SFVertices_[ Idx ].texCoords = sf::Vector2f( Vertices_[ Idx ].TexCoords_.X(), Vertices_[ Idx ].TexCoords_.Y() );
			}
			Dirty_ = false;
		}
	}
}