#include "FACEngine.h"
#include <fstream>
#include <Shlobj.h>

Log* Log::inst;

Log::Log() {
	inst = this;
}

Log::~Log() {

}

/* Prints a line to log file with optional arguments */
VOID Log::println(const WCHAR* fmt, ...) {
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	OutputDebugString(buf);

	std::wfstream outfile;

#ifdef _DEBUG
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		std::wstring s = buf;
		outfile << L"[" << Time::GetDateTimeString() << L"] " << s << "\n";
		std::wcout << L"[" << Time::GetDateTimeString() << L"] " << s << "\n";
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}


/* Prints to log file with optional arguments and no timestamp*/
VOID Log::print(const WCHAR* fmt, ...) {
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	OutputDebugString(buf);

	std::wfstream outfile;

#ifdef _DEBUG
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		std::wstring s = buf;
		outfile << s;
		std::wcout << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}

std::wstring Log::LogDirectory() {
	WCHAR Path[1024];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, PerGameSettings::GameName());
	CreateDirectory(Path, NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}

std::wstring Log::LogFile() {
	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::BootTime());
	wcscat_s(File, L".log");
	return File;
}

/**
	Prints a separator line in log file, without timestamp
*/
VOID Log::hline() {
	std::wstring s = L"\n---------------------------------------------------------------------------------\n\n";
	
#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		outfile << s;
		std::wcout << s;
		outfile.close();
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}