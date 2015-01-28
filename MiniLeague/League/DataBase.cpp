

#include "DataBase.h"



using namespace std;

CDataBase* CDataBase::m_pInstance = nullptr;

CDataBase* CDataBase::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new CDataBase();
	}

	return m_pInstance;
}

void CDataBase::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

CDataBase::CDataBase(void)
{
	printf("MySQL client version: %s\n", mysql_get_client_info());


	// 초기화

	conn = mysql_init(NULL);

	// DB 연결

	if (!mysql_real_connect(conn, DB_HOST,	DB_USER, DB_PASS,DB_NAME, 3306,(char *)NULL, 0)) {
			fprintf(stderr, "%s ", mysql_error(conn));
			exit(1);
	}
	else
		printf_s("connection success");
	//GetChampStatus(1);
}


CDataBase::~CDataBase(void)
{
	ReleaseInstance();
	mysql_close(conn);
}

void CDataBase::GetChampStatus(int id)
{
	std::string query = "select * from champion WHERE type_id = " ;
	query += to_string(id);
	query += ";";

	if (mysql_query(conn, query.c_str())) {
		fprintf(stderr, "%s ", mysql_error(conn));
		exit(1);
	}

	res = mysql_use_result(conn);
	num_fields = mysql_num_fields(res);
	while ((row = mysql_fetch_row(res)))
	{
		for(int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
}

MYSQL_RES* CDataBase::GetChampTableValue( int id )
{
	std::string query = "select * from champion WHERE type_id = " ;
	query += to_string(id);
	query += ";";

	if (mysql_query(conn, query.c_str())) {
		printf("%s ", mysql_error(conn));
		exit(1);
	}

	res = mysql_use_result(conn);

	return res;
}

MYSQL_RES* CDataBase::GetSkillTableValue( int id )
{
	std::string query = "select * from skill WHERE Skill_id = " ;
	query += to_string(id);
	query += ";";

	if (mysql_query(conn, query.c_str())) {
		printf("%s ", mysql_error(conn));
		exit(1);
	}

	res = mysql_use_result(conn);

	return res;
}



