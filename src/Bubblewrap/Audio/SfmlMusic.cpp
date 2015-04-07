#include "Bubblewrap/Audio/SfmlMusic.hpp"
#include "Bubblewrap/Base/Entity.hpp"
namespace Bubblewrap
{
	namespace Audio
	{
		SfmlMusic::SfmlMusic()
		{

		}

		void SfmlMusic::Initialise( Json::Value Params )
		{
			Music::Initialise( Params );
		}

		void  SfmlMusic::Copy( SfmlMusic* Target, SfmlMusic* Base )
		{
			Music::Copy( Target, Base );
		}

		void SfmlMusic::Update( float dt )
		{
			Offset_ += dt;
			if ( IsDirty_ )
			{
				IsDirty_ = false;
				Music_.setAttenuation( Attenuation_ );
				Music_.setLoop( Loop_ );
				Music_.setMinDistance( MinDistance_ );
				Music_.setPitch( Pitch_ );
				Music_.setPlayingOffset( sf::seconds( Offset_ ) );
				Music_.setVolume( Volume_ * 100.0f );
			}
			auto pos = GetParentEntity()->WorldPosition();
			Music_.setPosition( pos.X(), pos.Y(), pos.Z() );
			Offset_ = Music_.getPlayingOffset().asSeconds();
		}

		void SfmlMusic::OnAttach()
		{
			Music_.openFromFile( Filename_ );
			if ( Autoplay_ )
				Play();
		}

		void SfmlMusic::Play()
		{
			Music_.play();
		}

		void SfmlMusic::Pause()
		{
			Music_.pause();
		}

		void SfmlMusic::Stop()
		{
			Music_.stop();
		}

		Sound::Status SfmlMusic::GetStatus()
		{
			switch ( Music_.getStatus() )
			{
			case sf::SoundSource::Paused:
				return Sound::Status::Paused;
			case sf::SoundSource::Playing:
				return Sound::Status::Playing;
			case sf::SoundSource::Stopped:
				return Sound::Status::Stopped;
			}
			return Sound::Status::Stopped;
		}
	}
}