#include "Bubblewrap/Registers/BubblewrapSfmlSoundRegister.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/SfmlClock.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Audio/SfmlSound.hpp"
#include "Bubblewrap/Audio/SfmlSoundBuffer.hpp"
#include "Bubblewrap/Audio/SfmlMusic.hpp"

namespace Bubblewrap
{
	namespace Registers
	{
		void SfmlSoundRegister::Register( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;

			Register->RegisterCreator( "Sound", Audio::SfmlSound::Create, Audio::SfmlSound::CreateJson, Audio::SfmlSound::CopyDef, true );
			Register->RegisterCreator( "SoundBuffer", Audio::SfmlSoundBuffer::Create, Audio::SfmlSoundBuffer::CreateJson, Audio::SfmlSoundBuffer::CopyDef, true );
			Register->RegisterCreator( "Music", Audio::SfmlMusic::Create, Audio::SfmlMusic::CreateJson, Audio::SfmlMusic::CopyDef, true );

		}
	}
}