#include "Bubblewrap/Registers/SfmlRegisters.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/SfmlClock.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/SfmlWindow.hpp"
#include "Bubblewrap/Render/SfmlSprite.hpp"
#include "Bubblewrap/Render/SfmlTexture.hpp"
#include "Bubblewrap/Render/SfmlVertices.hpp"
#include "Bubblewrap/Render/SfmlText.hpp"
#include "Bubblewrap/Render/SfmlFont.hpp"
#include "Bubblewrap/Audio/SfmlSound.hpp"
#include "Bubblewrap/Audio/SfmlSoundBuffer.hpp"
#include "Bubblewrap/Audio/SfmlMusic.hpp"

namespace Bubblewrap
{
	namespace Registers
	{
		void SfmlRegisters::RegisterUtilities( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = ( Base::ObjectRegister* ) ObjectRegister;

			Register->RegisterCreator( "Clock", Base::SfmlClock::Create, Base::SfmlClock::CopyDef, true );

			Register->GetManager()->GetWindowManager().SetCreate( Render::SfmlWindow::Create );
		}

		void SfmlRegisters::RegisterGraphics( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;

			Register->RegisterCreator( "Sprite", Render::SfmlSprite::Create, Render::SfmlSprite::CopyDef, true );
			Register->RegisterCreator( "Texture", Render::SfmlTexture::Create, Render::SfmlTexture::CopyDef, true );
			Register->RegisterCreator( "Vertices", Render::SfmlVertices::Create, Render::SfmlVertices::CopyDef, true );
			
			Register->RegisterCreator( "Font", Render::SfmlFont::Create, Render::SfmlFont::CopyDef, true );
			Register->RegisterCreator( "Text", Render::SfmlText::Create, Render::SfmlText::CopyDef, true );

			Register->GetManager()->GetWindowManager().SetCreate(Render::SfmlWindow::Create);
		}

		void SfmlRegisters::RegisterAudio( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = ( Base::ObjectRegister* ) ObjectRegister;

			Register->RegisterCreator( "Sound", Audio::SfmlSound::Create, Audio::SfmlSound::CopyDef, true );
			Register->RegisterCreator( "SoundBuffer", Audio::SfmlSoundBuffer::Create, Audio::SfmlSoundBuffer::CopyDef, true );
			Register->RegisterCreator( "Music", Audio::SfmlMusic::Create, Audio::SfmlMusic::CopyDef, true );
		}
	}
}