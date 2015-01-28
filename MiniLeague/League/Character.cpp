#include "Character.h"
#include "Cleague.h"
#include "DataBase.h"
#include "mysql.h"
#include <string>

CCharacter::CCharacter(void)
{
	ChampImage_Q = NNSprite::Create(L"league/Champ/Question-Mark.png");
	ChampImage_Q ->SetPosition(0,0);
	AddChild(ChampImage_Q);
	type_id = -1;
}
CCharacter::~CCharacter(void)
{
}

void CCharacter::Render()
{
	NNObject::Render();
}

void CCharacter::Update( float dTime )
{
	NNObject::Update(dTime);
	if(type_id!= -1)
		ShowHPandMPbar();
}

void CCharacter::InitType( int Type_id )
{
	MYSQL_RES* res = CDataBase::GetInstance()->GetChampTableValue(Type_id + 1);

	int num_fields = mysql_num_fields(res);
	MYSQL_ROW row = mysql_fetch_row(res);

	type_id = Type_id;
	champ_name = row[1];
	skillQ_id = atoi(row[2]);
	SkillW_id = atoi(row[3]);
	SkillE_id = atoi(row[4]);
	SkillR_id = atoi(row[5]);
	Passive = atoi(row[6]);
	full_HP = atoi(row[7]);
	full_MP = atoi(row[8]);
	attackPower = atoi(row[9]);
	deffenceAttack = atoi(row[10]);
	deffenceMagic = atoi(row[11]);
	HPup = atoi(row[12]);
	MPup = atoi(row[13]);
	APup = atoi(row[14]);
	DAup = atoi(row[15]);
	DMup = atoi(row[16]);
	champImagaPath = row[17];
	HP_regen_per_sec = atoi(row[18]);
	MP_regen_per_sec = atoi(row[19]);

	mysql_free_result(res);

	ChampImage_Q->SetVisible(false);
	RemoveChild(ChampImage_Q);

	std::wstring champImagaPath_ws;
	champImagaPath_ws.assign (champImagaPath.begin(), champImagaPath.end());

	ChampImage = NNSprite::Create(champImagaPath_ws);
	ChampImage -> SetPosition(0,0);
	AddChild(ChampImage);

	Q = CSkill::Create();
	W = CSkill::Create();
	E = CSkill::Create();
	R = CSkill::Create();

	Q->InitSkill(skillQ_id);
	W->InitSkill(SkillW_id);
	E->InitSkill(SkillE_id);
	R->InitSkill(SkillR_id);

	InitCurrentStatus();
}

void CCharacter::InitCurrentStatus()
{
	current_HP = full_HP;
	current_MP = full_MP;
	current_AP = attackPower;
	current_MagicPower = 0;
	current_DA = deffenceAttack;
	current_DM = deffenceMagic;
	current_level = 1;

	HPbar = NNSpriteAtlas::Create(L"league/HPMP.png");
	MPbar = NNSpriteAtlas::Create(L"league/HPMP.png");
	HPbar->SetCutSize(0,0,300,15.f);
	MPbar->SetCutSize(0,50,300,20.f);

	HPbar->SetPosition(5,5);
	MPbar->SetPosition(5,30);

	AddChild(HPbar,20);
	AddChild(MPbar,20);
}

void CCharacter::ShowHPandMPbar()
{
	int HPlength = 300*current_HP/full_HP;
	int MPlength;
	
	if(full_MP == 0)
		MPlength = 300;
	else
		MPlength = 300*current_MP/full_MP;

	HPbar -> SetCutSize(0,0,HPlength,20.f);
	MPbar -> SetCutSize(0,50,MPlength,70.f);
}

void CCharacter::Attack(CCharacter* rival)
{
	if(current_HP > 0)
		rival->beAttacked(attackPower,0);
}

void CCharacter::AttackQ( CCharacter* rival )
{
	if(current_MP >= (Q->GetUseMP()) && current_HP >0)
	{
		current_MP = current_MP - (Q->GetUseMP());
		rival->beAttacked(Q->GetAttackPower(),Q->GetMagicPower());
	}
}

void CCharacter::AttackW( CCharacter* rival )
{
	if(current_MP >= (W->GetUseMP()) && current_HP >0)
	{
		current_MP = current_MP - (W->GetUseMP());
		rival->beAttacked(W->GetAttackPower(),W->GetMagicPower());
	}
}

void CCharacter::AttackE( CCharacter* rival )
{
	if(current_MP >= (W->GetUseMP()) && current_HP >0)
	{
		current_MP = current_MP - (E->GetUseMP());
		rival->beAttacked(E->GetAttackPower(),E->GetMagicPower());
	}
}

void CCharacter::AttackR( CCharacter* rival )
{
	if(current_MP >= (R->GetUseMP()) && current_HP >0)
	{
		current_MP = current_MP - (R->GetUseMP());
		rival->beAttacked(R->GetAttackPower(),R->GetMagicPower());
	}
}

void CCharacter::beAttacked( int attackPower, int magicPower )
{
	int APDamage = attackPower - deffenceAttack;
	int MPDamage = magicPower - deffenceMagic;

	if (APDamage < 0)
		APDamage =0;
	if (MPDamage < 0)
		MPDamage =0;
	current_HP = current_HP - APDamage - MPDamage;
}

