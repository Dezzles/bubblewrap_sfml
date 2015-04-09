#ifndef BUBBLEWRAP_SFML_WINDOW_HPP
#define BUBBLEWRAP_SFML_WINDOW_HPP


#include "Bubblewrap/Managers/BaseManager.hpp"
#include "Bubblewrap/Render/Window.hpp"
#include "SFML/Graphics.hpp"
#include <functional>
namespace Bubblewrap
{
	namespace Render
	{
		/*! An implementation of Window using SFML's sf::RenderWindow */
		class SfmlWindow
			: public Window
		{
		public:
			/*! Creates an SfmlWindow
			\param Settings The settings that should be used to setup the window */
			SfmlWindow( Window::WindowSettings Settings );

			void Update( float dt );
			void Display();
			void HandleEvents();

			/*! Performs a function on the RenderWindow 
			\param Function The function that should be called on Window
			*/
			void Do( std::function<void( sf::RenderWindow& Window )> Function );

			/*! Creates a new Window
			\param Params a pointer to the parameters that should be used to create the window
			\returns A pointer to a new window
			*/
			static Window* Create(void *Params);
		private:

			sf::RenderWindow* sfWindow_;
		};

	}
}

#endif