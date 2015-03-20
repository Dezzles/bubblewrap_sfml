#include "Bubblewrap/Registers/BubblewrapGraphicsRegister.hpp"
#include "Bubblewrap/Base/ObjectRegister.hpp"
#include "Bubblewrap/Base/SfmlClock.hpp"
#include "Bubblewrap/Managers/Managers.hpp"
#include "Bubblewrap/Render/SfmlWindow.hpp"
#include "Bubblewrap/Render/SfmlSprite.hpp"
#include "Bubblewrap/Render/SfmlTexture.hpp"
#include "Bubblewrap/Render/SfmlVertices.hpp"
namespace Bubblewrap
{
	namespace Registers
	{
		void GraphicsRegister::Register( void* ObjectRegister )
		{
			Base::ObjectRegister* Register = (Base::ObjectRegister*) ObjectRegister;

			Register->RegisterCreator( "Clock", Base::SfmlClock::Create, Base::SfmlClock::CreateJson, Base::SfmlClock::CopyDef, true );
			Register->RegisterCreator( "Sprite", Render::SfmlSprite::Create, Render::SfmlSprite::CreateJson, Render::SfmlSprite::CopyDef, true );
			Register->RegisterCreator( "Texture", Render::SfmlTexture::Create, Render::SfmlTexture::CreateJson, Render::SfmlTexture::CopyDef, true );
			Register->RegisterCreator( "Vertices", Render::SfmlVertices::Create, Render::SfmlVertices::CreateJson, Render::SfmlVertices::CopyDef, true );

			Register->GetManager()->GetWindowManager().SetCreate(Render::SfmlWindow::Create);
		}
	}
}