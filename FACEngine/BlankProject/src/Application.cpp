#include "pch.h"
#include "Application.h"
#include "Platform/Win32/WinEntry.h"

ENTRYAPP(Application)

Application::Application() {

}

Application::~Application() {

}

VOID Application::SetupPerGameSettings() {
	// Set per-game settings
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}

VOID Application::Initialize() {
	Log::hline();
	Log::println(L"Application Starting...");
	Log::println(L"Game Name: %s", PerGameSettings::GameName());
	Log::println(L"Boot Time: %s", Time::GetDateTimeString().c_str());
	Log::hline();

	//Logger::startMTail();
}

VOID Application::Update() {
	Log::print(L". ");
}
