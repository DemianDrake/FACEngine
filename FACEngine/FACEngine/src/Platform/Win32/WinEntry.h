#include "FACEngine.h"

#include "IApplication.h"

extern IApplication* EntryApplication();

INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	auto EntryApp = EntryApplication();

	PerGameSettings gameSettings;

	EntryApp->SetupPerGameSettings();

	#ifdef _DEBUG
		AllocConsole();
		FILE* newstdin = nullptr;
		FILE* newstdout = nullptr;
		FILE* newstderr = nullptr;

		freopen_s(&newstdin, "CONIN$", "r", stdin);
		freopen_s(&newstdout, "CONOUT$", "w", stdout);
		freopen_s(&newstderr, "CONOUT$", "w", stderr);
	#endif


	Log log;

	EntryApp->Initialize();

	MSG msg = { 0 };
	while (msg.message != WM_QUIT) {
		//If there are Window messages, process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			EntryApp->Update();
		}
	}

	return 0;
}