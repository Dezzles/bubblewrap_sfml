#include "Bubblewrap/Audio/SfmlSound.hpp"
#include "Bubblewrap/Audio/SfmlSoundBuffer.hpp"
#include "Bubblewrap/Base/Entity.hpp"
namespace Bubblewrap
{
	namespace Audio
	{
		SfmlSound::SfmlSound()
		{

		}

		void SfmlSound::Initialise( Json::Value Params )
		{
			Sound::Initialise( Params );
		}

		void SfmlSound::Copy( SfmlSound* Target, SfmlSound* Base )
		{
			Sound::Copy( Target, Base );
		}

		void SfmlSound::Update( float dt )
		{
			if ( GetStatus() == Sound::Status::Playing )
				Offset_ += dt;
			if ( IsDirty_ )
			{
				IsDirty_ = false;
				Sound_.setAttenuation( Attenuation_ );
				Sound_.setLoop( Loop_ );
				Sound_.setMinDistance( MinDistance_ );
				Sound_.setPitch( Pitch_ );
				Sound_.setPlayingOffset( sf::seconds( Offset_ ) );
				Sound_.setVolume( Volume_ * 100.0f );
			}
			auto pos = GetParentEntity()->WorldPosition();
			Sound_.setPosition( pos.X(), pos.Y(), pos.Z() );
			Offset_ = Sound_.getPlayingOffset().asSeconds();

		}

		void SfmlSound::OnAttach()
		{
			Sound::OnAttach();
			if ( Buffer_ != nullptr )
			{
				SfBuffer_ = dynamic_cast<SfmlSoundBuffer*>( Buffer_ );
				Sound_.setBuffer( *SfBuffer_->GetBuffer() );
			}
		}

		void SfmlSound::Play()
		{
			Sound_.play();
		}

		void SfmlSound::Pause()
		{
			Sound_.pause();
		}

		void SfmlSound::Stop()
		{
			Sound_.stop();
		}

		Sound::Status SfmlSound::GetStatus()
		{
			switch ( Sound_.getStatus() )
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