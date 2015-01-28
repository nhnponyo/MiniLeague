#include "Background.h"
#include "Cleague.h"


CBackground::CBackground(void)
{
	m_BackgroundImage = NNSprite::Create( L"league/background.jpg");
	m_BackgroundImage->SetPosition(0.0f, 0.0f);
	AddChild( m_BackgroundImage );
}


CBackground::~CBackground(void)
{
}

void CBackground::Render()
{
	NNObject::Render();
}

void CBackground::Update( float dTime )
{
	NNObject::Update(dTime);
}
