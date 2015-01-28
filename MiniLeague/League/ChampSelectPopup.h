#pragma once
#include "nnobject.h"
#include "NNMacroSet.h"
#include "NNSprite.h"
#include "UIButton.h"
#include "Config.h"

class CChampSelectPopup :
	public NNObject
{
public:
	CChampSelectPopup(void);
	virtual~CChampSelectPopup(void);

public:
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CChampSelectPopup);

private:
	NNSprite	*m_pOptionBackground;
	CUIButton	*m_pGameStart;
	CUIButton	*ChampionSelect[MAX_CHAMPION];

	int			clickNumber; //1 = left 2 = right

public:
	void OperateButton();
	int GetClickNumber() {return clickNumber;}
};

