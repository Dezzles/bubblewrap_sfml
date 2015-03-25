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

			void Refresh();
			void Draw();
		protected:

			sf::Vertex* SFVertices_;

			unsigned int SFReservedCount_;

		};
	}
}


#endif