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
		class SfmlWindow 
			: public Window
		{
		public:
			struct WindowSettings
			{
				int Width_;
				int Height_;
				std::string Title_;
				std::string Name_;
			};

			SfmlWindow( Window::WindowSettings Settings );

			void Update( float dt );
			void Display();
			void HandleEvents();
			void Do( std::function<void( sf::RenderWindow& Window )> Function );

			static Window* Create(void *Params);
		private:

			sf::RenderWindow* sfWindow_;
		};

	}
}

#endif