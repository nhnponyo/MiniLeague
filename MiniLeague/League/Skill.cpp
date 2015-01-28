#include "Skill.h"
#include "NNObject.h"
#include "DataBase.h"
#include "mysql.h"
#include <string>
#include "Character.h"


CSkill::CSkill(void)
{
}

CSkill::~CSkill(void)
{
}

void CSkill::Render()
{
	NNObject::Render();
}

void CSkill::Update( float dTime )
{
	NNObject::Update(dTime);
}

void CSkill::InitSkill( int id )
{
	MYSQL_RES* res = CDataBase::GetInstance()->GetSkillTableValue(id);

	int num_fields = mysql_num_fields(res);
	MYSQL_ROW row = mysql_fetch_row(res);

	id = id;
	name = row[1];
	Type = row[2]; // A- attack H-Hill B-버프 T-변신
	attackPower = atoi(row[3]);
	attackPowerUP = atoi(row[4]);
	magicPower = atoi(row[5]);
	magicPowerUP = atoi(row[6]);
	deffensePower = atoi(row[7]);
	damageFromAP = atof(row[8]);
	damageFromMP = atof(row[9]);
	MP_use = atoi(row[10]);
	HP_use = atoi(row[11]);
	cooltime = atoi(row[12]);
	info = row[13];

	SkillLevel = 1;
	mysql_free_result(res);
}
