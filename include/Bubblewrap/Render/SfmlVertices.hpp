#ifndef BUBBLEWRAP_SFML_VERTICES_HPP
#define BUBBLEWRAP_SFML_VERTICES_HPP

#include "Bubblewrap/Base/Defines.hpp"
#include "Bubblewrap/Render/Vertices.hpp"
#include "Bubblewrap/Render/Drawable.hpp"
#include "Bubblewrap/Render/Types.hpp"
#include "Bubblewrap/Base/Base.hpp"
#include "SFML/Graphics.hpp"
namespace Bubblewrap
{
	namespace Render
	{

		class SfmlVertices
			: public Vertices
		{
		public:
			SfmlVertices();
			~SfmlVertices();
			void Initialise( Json::Value Params );

			CREATE_REGISTER_OVERRIDE( SfmlVertices, Vertices );

			virtual void Update( float dt );
			virtual void OnAttach();

			void AddVertex( Vertex V );
			void Reserve( unsigned int Amount );
			void SetVertex( unsigned int Idx, Vertex V );
			void Refresh();
			void SetPrimitiveType( Primitives PrimitiveType );
			void Draw();
		protected:

			Vertex* Vertices_;
			sf::Vertex* SFVertices_;

			unsigned int VertexCount_;
			unsigned int ReservedCount_;
			unsigned int SFReservedCount_;

			Primitives PrimitiveType_;

			bool Dirty_;
		};
	}
}


#endif