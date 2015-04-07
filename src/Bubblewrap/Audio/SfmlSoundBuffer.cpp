#include "Bubblewrap/Audio/SfmlSoundBuffer.hpp"

namespace Bubblewrap
{
	namespace Audio
	{
		SfmlSoundBuffer::SfmlSoundBuffer()
		{

		}

		void SfmlSoundBuffer::Initialise( Json::Value Params )
		{
			SoundBuffer::Initialise( Params );
			Buffer_.loadFromFile( Filename_ );
		}

		void SfmlSoundBuffer::Copy( SfmlSoundBuffer* Target, SfmlSoundBuffer* Base )
		{
			SoundBuffer::Copy( Target, Base );
		}

		void SfmlSoundBuffer::Update( float dt )
		{

		}

		void SfmlSoundBuffer::OnAttach()
		{
		}

		sf::SoundBuffer* SfmlSoundBuffer::GetBuffer()
		{
			return &Buffer_;
		}
	}
}