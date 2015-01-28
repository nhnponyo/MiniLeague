#pragma once
class CPlayer
{

private:
	static CPlayer* m_pInstance;

public:
	CPlayer(void);
	~CPlayer(void);

public:
	static CPlayer* GetInstance();
	static void ReleaseInstance();

public:
	bool Init();

private:
	int m_globalMoney;
	float m_clearedStage;//2.1, 3.4 ������ ����� �������� ǥ���Ϸ���
	//������Ʈ ��Ȳ ������ �ֱ�

public:
	int GetGlobalMoney(){return m_globalMoney;};
	float GetClearedStage() {return m_clearedStage;};
	
	void SetGlobalMoney(int money) {m_globalMoney = money;};
	void SetClearedStage(float ClearedStage) {m_clearedStage = ClearedStage;};

};

