#ifndef BUBBLEWRAP_SFML_RENDER_SFMLVERTICES_HPP
#define BUBBLEWRAP_SFML_RENDER_SFMLVERTICES_HPP

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

		/*! An implementation of Vertices using SFML's sf::Vertex*/
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
			/*! A pointer to an array of vertices used to draw*/
			sf::Vertex* SFVertices_;

			/*! The number of vertices we have currently stored in SFVertices_ */
			unsigned int SFReservedCount_;

		};
	}
}


#endif