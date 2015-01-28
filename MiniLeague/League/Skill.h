#pragma once
#include "NNMacroSet.h"
#include "NNObject.h"

class CSkill : public NNObject
{
public:
	CSkill(void);
	CSkill::CSkill(int id);
	virtual ~CSkill(void);

public:
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CSkill);

private:
	int id;
	std::string name;
	std::string Type; // A- attack H-Hill B-버프 T-변신
	int attackPower;
	int attackPowerUP;
	int magicPower;
	int magicPowerUP;
	int deffensePower;
	float damageFromAP;
	float damageFromMP;
	int MP_use;
	int HP_use;
	int cooltime;
	std::string info;
	int SkillLevel;

public:
	void InitSkill(int id);
	int GetUseMP() {return MP_use;}
	int GetAttackPower() {return attackPower+(SkillLevel-1)*attackPowerUP;}
	int GetMagicPower() {return magicPower+(SkillLevel-1)*magicPowerUP;}
};