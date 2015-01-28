#include "Cleague.h"
#include "NNPoint.h"
#include "NNInputSystem.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include <tchar.h>
#include <time.h>

Cleague* Cleague::m_pInstance = nullptr;

Cleague* Cleague::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new Cleague();
	}

	return m_pInstance;
}

void Cleague::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

Cleague::Cleague(void)
{	
	InitLeague();
	CheckFirst = false;
}

Cleague::~Cleague(void)
{
	ReleaseInstance();
}

void Cleague::Render()
{
	NNObject::Render();
}

void Cleague::Update( float dTime )
{
	NNObject::Update(dTime);

	if(m_pSelectPopup->GetClickNumber() == 0)
		OperateButton();
}

void Cleague::InitLeague()
{
	m_currentPlayer = LEFT_HERO;
	m_pBackground = CBackground::Create();
	m_pBackground->SetPosition(0.0f, 0.0f);

	//button Init
	m_pAttackLeft = CUIButton::Create(L"league/UIbuttons/doran.png", L"league/UIbuttons/doran_pressed.png");
	m_pAttackLeft->SetPosition(1.0f, 500.0f);
	m_pQSkillLeft = CUIButton::Create(L"league/UIbuttons/Letter-Q-icon.png",L"league/UIbuttons/Letter-Q-icon_pressed.png");
	m_pQSkillLeft->SetPosition(102.0f, 500.0f);
	m_pWSkillLeft = CUIButton::Create(L"league/UIbuttons/Letter-W-icon.png",L"league/UIbuttons/Letter-W-icon_pressed.png");
	m_pWSkillLeft->SetPosition(203.0f, 500.0f);
	m_pESkillLeft = CUIButton::Create(L"league/UIbuttons/Letter-E-icon.png",L"league/UIbuttons/Letter-E-icon_pressed.png");
	m_pESkillLeft->SetPosition(304.0f, 500.0f);
	m_pRSkillLeft = CUIButton::Create(L"league/UIbuttons/Letter-R-icon.png",L"league/UIbuttons/Letter-R-icon_pressed.png");
	m_pRSkillLeft->SetPosition(405.0f, 500.0f);
	m_pAttackRight = CUIButton::Create(L"league/UIbuttons/doran.png", L"league/UIbuttons/doran_pressed.png");
	m_pAttackRight->SetPosition(506.0f, 500.0f);
	m_pQSkillRight = CUIButton::Create(L"league/UIbuttons/Letter-Q-icon.png",L"league/UIbuttons/Letter-Q-icon_pressed.png");
	m_pQSkillRight->SetPosition(607.0f , 500.0f);
	m_pWSkillRight = CUIButton::Create(L"league/UIbuttons/Letter-W-icon.png",L"league/UIbuttons/Letter-W-icon_pressed.png");
	m_pWSkillRight->SetPosition(708.0f , 500.0f);
	m_pESkillRight = CUIButton::Create(L"league/UIbuttons/Letter-E-icon.png",L"league/UIbuttons/Letter-E-icon_pressed.png");
	m_pESkillRight->SetPosition(809.0f , 500.0f);
	m_pRSkillRight = CUIButton::Create(L"league/UIbuttons/Letter-R-icon.png",L"league/UIbuttons/Letter-R-icon_pressed.png");
	m_pRSkillRight->SetPosition(910.0f , 500.0f);

	AddChild( m_pBackground);
	AddChild( m_pAttackLeft , 20);
	AddChild( m_pQSkillLeft , 20);
	AddChild( m_pWSkillLeft , 20);
	AddChild( m_pESkillLeft , 20);
	AddChild( m_pRSkillLeft , 20);
	AddChild( m_pAttackRight , 20);
	AddChild( m_pQSkillRight , 20);
	AddChild( m_pWSkillRight , 20);
	AddChild( m_pESkillRight , 20);
	AddChild( m_pRSkillRight , 20);

	m_pLeftChamp = CCharacter::Create();
	m_pLeftChamp -> SetPosition(30,50);
	m_pRightChamp = CCharacter::Create();
	m_pRightChamp -> SetPosition(700,50);

	m_pLeftChamp->location = LEFT;
	m_pRightChamp->location = RIGHT;

	AddChild(m_pLeftChamp);
	AddChild(m_pRightChamp);

	m_pSelectPopup = CChampSelectPopup::Create();
	m_pSelectPopup->SetPosition(0,0);
	AddChild(m_pSelectPopup);

}

void Cleague::InitLeftChamp( int Type_id )
{
	m_pLeftChamp -> InitType(Type_id);
}

void Cleague::InitRightChamp( int Type_id )
{
	m_pRightChamp -> InitType(Type_id);
}

void Cleague::ClearChamp()
{
	RemoveChild(m_pLeftChamp);
	RemoveChild(m_pRightChamp);

	m_pLeftChamp = CCharacter::Create();
	m_pLeftChamp -> SetPosition(30,50);
	m_pRightChamp = CCharacter::Create();
	m_pRightChamp -> SetPosition(700,50);

	AddChild(m_pLeftChamp);
	AddChild(m_pRightChamp);
}

void Cleague::OperateButton()
{
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN) 
	{
		if(m_pAttackLeft -> CheckButtonArea())
		{
			m_pLeftChamp->Attack(m_pRightChamp);
		}
		else if(m_pQSkillLeft -> CheckButtonArea())
		{
			m_pLeftChamp->AttackQ(m_pRightChamp);
		}
		else if(m_pWSkillLeft -> CheckButtonArea())
		{
			m_pLeftChamp->AttackW(m_pRightChamp);
		}
		else if(m_pESkillLeft -> CheckButtonArea())
		{
			m_pLeftChamp->AttackE(m_pRightChamp);
		}
		else if(m_pRSkillLeft -> CheckButtonArea())
		{
			m_pLeftChamp->AttackR(m_pRightChamp);
		}
		else if(m_pAttackRight -> CheckButtonArea())
		{
			m_pRightChamp->Attack(m_pLeftChamp);
		}
		else if(m_pQSkillRight ->CheckButtonArea())
		{
			m_pRightChamp->AttackQ(m_pLeftChamp);
		}
		else if(m_pWSkillRight -> CheckButtonArea())
		{
			m_pRightChamp->AttackW(m_pLeftChamp);
		}
		else if(m_pESkillRight -> CheckButtonArea())
		{
			m_pRightChamp->AttackE(m_pLeftChamp);
		}
		else if(m_pRSkillRight -> CheckButtonArea())
		{
			m_pRightChamp->AttackR(m_pLeftChamp);
		}
	}
}
