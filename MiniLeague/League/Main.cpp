
#include "NNApplication.h"
#include "NNAudioSystem.h"

#include "DataBase.h"
#include "Cleague.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd ){
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );
	AllocConsole();
	FILE* console;
	freopen_s( &console, "CONOUT$", "wt", stdout );

	printf_s("Console Open \n");
#endif 

	CDataBase* database = CDataBase::GetInstance();

	NNApplication* Application = NNApplication::GetInstance();
	Application->Init( L"League of legend", 1024, 640, D2D );

	NNSceneDirector::GetInstance()->ChangeScene( Cleague::GetInstance() );


	Application->Run();

	Application->Release();

	database->ReleaseInstance();
#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}