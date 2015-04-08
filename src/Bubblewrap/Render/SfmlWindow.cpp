#include "Bubblewrap/Render/SfmlWindow.hpp"
#include "Bubblewrap/Managers/Managers.hpp"

#include "Bubblewrap/Events/Events.hpp"
#include "Bubblewrap/Events/EventManager.hpp"
#include "SFML/Graphics.hpp"
#include "Bubblewrap/Events/SfmlKeyTranslator.hpp"
namespace Bubblewrap
{
	namespace Render
	{
		SfmlWindow::SfmlWindow( Window::WindowSettings Settings )
			: Window( Settings )
		{
			Window_ = sfWindow_ = new sf::RenderWindow( sf::VideoMode( Settings.Width_, Settings.Height_ ), Settings.Title_ );
		}

		Window* SfmlWindow::Create( void* Params )
		{
			Window::WindowSettings* Settings = ( Window::WindowSettings* )Params;
			return ( Window* ) ( new SfmlWindow( *Settings ) );
		}
	

		void SfmlWindow::Update( float dt )
		{
			sfWindow_->clear();
		}

		void SfmlWindow::Display()
		{
			Window::Display();
			sfWindow_->display();
		}

		void SfmlWindow::HandleEvents()
		{
			sf::Event event;
			while ( sfWindow_->pollEvent( event ) )
			{
				// sm->Input( event );
				//if ( event.type == sf::Event::Closed )
				//window.close();
				if ( ( event.type == sf::Event::KeyPressed ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyDown;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().QueueEvent( evt );
				}
				else if ( ( event.type == sf::Event::KeyReleased ) )
				{
					auto code = Bubblewrap::Events::TranslateKey( event.key.code );
					Events::InputData* newEvent = new Events::InputData();
					newEvent->InputType_ = Events::InputData::InputType::KeyUp;
					newEvent->Key_ = Bubblewrap::Events::TranslateKey( event.key.code );
					newEvent->Alt_ = event.key.alt;
					newEvent->Control_ = event.key.control;
					newEvent->Shift_ = event.key.shift;
					Events::Event evt = Events::Event( Events::EventTypes::Input, newEvent );
					GetManagers().GetEventManager().QueueEvent( evt );
				}
			}

		}


	}
}