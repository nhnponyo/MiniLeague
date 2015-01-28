#pragma once
#include "NNMacroSet.h"
#include "NNObject.h"
#include "Skill.h"
#include "Config.h"
#include "NNSprite.h"
#include "NNSpriteAtlas.h"

enum Champ_location
{
	LEFT,
	RIGHT
};

class CCharacter : public NNObject
{
public:
	CCharacter(void);
	CCharacter(int Type_id);
	virtual ~CCharacter(void);

public:
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CCharacter);

	void InitType(int Type_id);

private:
	int type_id;
	std::string champ_name;
	int skillQ_id;
	int SkillW_id;
	int SkillE_id;
	int SkillR_id;
	int Passive;
	int full_HP;
	int full_MP;
	int attackPower;
	int deffenceAttack;
	int deffenceMagic;
	int HPup;
	int MPup;
	int APup;
	int DAup;
	int DMup;
	std::string champImagaPath; 
	int HP_regen_per_sec;
	int MP_regen_per_sec;

	CSkill* Q ;
	CSkill* W ;
	CSkill* E ;
	CSkill* R ;

	NNSprite*	ChampImage_Q;
	NNSprite*	ChampImage;

public:
	int GetSkillQ() {return skillQ_id;}
	int GetSkillW() {return SkillW_id;}
	int GetSkillE() {return SkillE_id;}
	int GetSkillR() {return SkillR_id;}
	int GetPassive() {return Passive;}

private:
	//현재 상태 변수
	int current_HP;
	int current_MP;
	int current_AP;
	int current_MagicPower;
	int current_DA;
	int current_DM;
	int current_level;

	NNSpriteAtlas* HPbar;
	NNSpriteAtlas* MPbar;

public:
	void InitCurrentStatus();
	void ShowHPandMPbar();

	void Attack(CCharacter* rival);
	void AttackQ(CCharacter* rival);
	void AttackW(CCharacter* rival);
	void AttackE(CCharacter* rival);
	void AttackR(CCharacter* rival);

	void beAttacked(int attackPower, int magicPower);

	Champ_location location;

	int GetCurrentMP() {return current_MP;}
	void SetCurrentMP(int MP) { current_MP = MP;}

};

