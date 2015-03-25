#include "Bubblewrap/Registers/BubblewrapSfmlGraphicsRegister.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/SfmlClock.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/SfmlWindow.hpp"
#include "Bubblewrap/Render/SfmlSprite.hpp"
#include "Bubblewrap/Render/SfmlTexture.hpp"
#include "Bubblewrap/Render/SfmlVertices.hpp"
#include "Bubblewrap/Render/SfmlText.hpp"
#include "Bubblewrap/Render/SfmlFont.hpp"
namespace Bubblewrap
{
	namespace Registers
	{
		void SfmlGraphicsRegister::Register( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;

			Register->RegisterCreator( "Clock", Base::SfmlClock::Create, Base::SfmlClock::CreateJson, Base::SfmlClock::CopyDef, true );
			Register->RegisterCreator( "Sprite", Render::SfmlSprite::Create, Render::SfmlSprite::CreateJson, Render::SfmlSprite::CopyDef, true );
			Register->RegisterCreator( "Texture", Render::SfmlTexture::Create, Render::SfmlTexture::CreateJson, Render::SfmlTexture::CopyDef, true );
			Register->RegisterCreator( "Vertices", Render::SfmlVertices::Create, Render::SfmlVertices::CreateJson, Render::SfmlVertices::CopyDef, true );
			
			Register->RegisterCreator( "Font", Render::SfmlFont::Create, Render::SfmlFont::CreateJson, Render::SfmlFont::CopyDef, true );
			Register->RegisterCreator( "Text", Render::SfmlText::Create, Render::SfmlText::CreateJson, Render::SfmlText::CopyDef, true );

			Register->GetManager()->GetWindowManager().SetCreate(Render::SfmlWindow::Create);
		}
	}
}