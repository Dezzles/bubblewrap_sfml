#include "Bubblewrap/Registers/BubblewrapSfmlSoundRegister.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/SfmlClock.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Sound/SfmlSound.hpp"
#include "Bubblewrap/Sound/SfmlSoundBuffer.hpp"
#include "Bubblewrap/Sound/SfmlMusic.hpp"

namespace Bubblewrap
{
	namespace Registers
	{
		void SfmlSoundRegister::Register( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;

			Register->RegisterCreator( "Sound", Sound::SfmlSound::Create, Sound::SfmlSound::CreateJson, Sound::SfmlSound::CopyDef, true );
			Register->RegisterCreator( "SoundBuffer", Sound::SfmlSoundBuffer::Create, Sound::SfmlSoundBuffer::CreateJson, Sound::SfmlSoundBuffer::CopyDef, true );
			Register->RegisterCreator( "Music", Sound::SfmlMusic::Create, Sound::SfmlMusic::CreateJson, Sound::SfmlMusic::CopyDef, true );

		}
	}
}