#pragma once

#include "NNApplication.h"
#include "NNAudioSystem.h"
#include <mysql.h>
#include <iostream>
#include <stdio.h>
#include "Config.h"
#include <string>

#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "ws2_32.lib")

class CDataBase
{
private :
	static CDataBase* m_pInstance;
	CDataBase(void);
	virtual ~CDataBase(void);

	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	int num_fields;

public:
	static CDataBase* GetInstance();
	static void ReleaseInstance();

	MYSQL_RES* GetChampTableValue(int id);
	MYSQL_RES* GetSkillTableValue(int id);
	void CDataBase::GetChampStatus(int id);
};

