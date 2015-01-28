#include "ChampSelectPopup.h"
#include "NNInputSystem.h"
#include "Cleague.h"

CChampSelectPopup::CChampSelectPopup(void)
{
	//champion select
	m_pOptionBackground = NNSprite::Create(L"league/UIbuttons/select/option.png");
	m_pOptionBackground->SetPosition(400,200);
	m_pOptionBackground->SetVisible(false);

	m_pGameStart = CUIButton::Create(L"league/UIButtons/NewGame.png",L"league/UIButtons/NewGame.png"); 
	m_pGameStart->SetPosition(370, 50);
	AddChild(m_pGameStart);

	ChampionSelect[0] = CUIButton::Create(L"league/UIButtons/select/1.png",L"league/UIButtons/select/1.png");
	ChampionSelect[0]->SetPosition(400,200);
	ChampionSelect[1] = CUIButton::Create(L"league/UIButtons/select/2.png",L"league/UIButtons/select/2.png");
	ChampionSelect[1]->SetPosition(460,200);
	ChampionSelect[2] = CUIButton::Create(L"league/UIButtons/select/3.png",L"league/UIButtons/select/3.png");
	ChampionSelect[2]->SetPosition(520,200);
	ChampionSelect[3] = CUIButton::Create(L"league/UIButtons/select/4.png",L"league/UIButtons/select/4.png");
	ChampionSelect[3]->SetPosition(580,200);
	ChampionSelect[4] = CUIButton::Create(L"league/UIButtons/select/5.png",L"league/UIButtons/select/5.png");
	ChampionSelect[4]->SetPosition(400,260);
	ChampionSelect[5] = CUIButton::Create(L"league/UIButtons/select/6.png",L"league/UIButtons/select/6.png");
	ChampionSelect[5]->SetPosition(460,260);
	ChampionSelect[6] = CUIButton::Create(L"league/UIButtons/select/7.png",L"league/UIButtons/select/7.png");
	ChampionSelect[6]->SetPosition(520,260);

	AddChild(m_pOptionBackground);
	for(int i=0; i<MAX_CHAMPION; ++i)
	{
		ChampionSelect[i]->SetVisible(false);
		AddChild(ChampionSelect[i],30);
	}
	clickNumber = 0;
}


CChampSelectPopup::~CChampSelectPopup(void)
{
}

void CChampSelectPopup::Render()
{
	NNObject::Render();
}

void CChampSelectPopup::Update( float dTime )
{
	NNObject::Update(dTime);

	OperateButton();
}

void CChampSelectPopup::OperateButton()
{
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN) 
	{
		//NNPoint cursorPosition = NNInputSystem::GetInstance()->GetMousePosition();

		if(m_pGameStart->CheckButtonArea() && clickNumber == 0 )
		{
			//printf_s("gamestart");
			clickNumber = 1;
			m_pGameStart -> SetVisible(false);
			for(int i=0; i<MAX_CHAMPION; ++i)
				ChampionSelect[i]->SetVisible(true);
			if(Cleague::GetInstance()->CheckFirst == false)
			{
				Cleague::GetInstance()->CheckFirst = true;
				return;
			}
			else
			{
				Cleague::GetInstance()->ClearChamp();
				printf("first\n");
			}
			return;
		}

		if(clickNumber == 1)
		{
			for(int i=0;i<MAX_CHAMPION;++i)
			{
				if(ChampionSelect[i]->CheckButtonArea())
				{
					Cleague::GetInstance()->InitLeftChamp(i);
					clickNumber = 2;
					return;
				}
			}
		}
		if(clickNumber == 2)
		{
			for(int i=0;i<MAX_CHAMPION;++i)
			{
				if(ChampionSelect[i]->CheckButtonArea())
				{
					Cleague::GetInstance()->InitRightChamp(i);
					clickNumber = 0;
					for(int i=0; i<MAX_CHAMPION; ++i)
						ChampionSelect[i]->SetVisible(false);
					m_pGameStart -> SetVisible(true);
					return;
				}
			}
		}
	}
}