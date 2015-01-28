#pragma once
#include "nnscene.h"
#include "Background.h"
#include "UIButton.h"
#include "Config.h"
#include "ChampSelectPopup.h"
#include "Character.h"
//#define MAX_CHAMPION 7

enum TURN{
	LEFT_HERO,
	RIGHT_HERO
};

class Cleague : public NNScene
{
private :
	static Cleague* m_pInstance;
	Cleague(void);
	virtual ~Cleague(void);

public:
	static Cleague* GetInstance();
	static void ReleaseInstance();

private :
	CBackground *m_pBackground;
	CUIButton	*m_pAttackLeft;
	CUIButton	*m_pAttackRight;
	CUIButton	*m_pQSkillLeft;
	CUIButton	*m_pWSkillLeft;
	CUIButton	*m_pESkillLeft;
	CUIButton	*m_pRSkillLeft;
	CUIButton	*m_pQSkillRight;
	CUIButton	*m_pWSkillRight;
	CUIButton	*m_pESkillRight;
	CUIButton	*m_pRSkillRight;

	CChampSelectPopup	*m_pSelectPopup;

	CCharacter	*m_pLeftChamp;
	CCharacter	*m_pRightChamp;

	void InitLeague();
public:
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(Cleague);

public :
	TURN m_currentPlayer;
	
	void InitLeftChamp(int Type_id);
	void InitRightChamp(int Type_id);

	void ClearChamp();

	bool CheckFirst; // 최초 클리어
	void OperateButton();
};
