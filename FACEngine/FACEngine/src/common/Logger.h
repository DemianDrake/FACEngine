#pragma once

#include <string>

class FACENGINE_API Log {

private:
	// Singleton
	static Log* inst; 
public:
	static Log* instance() {
		return inst;
	}

	Log();
	~Log();

	/* Prints a line to Log File with timestamp */
	static VOID println(const WCHAR* fmt, ...);

	/* Prints to Log File */
	static VOID print(const WCHAR* fmt, ...);

	static std::wstring LogDirectory();
	
	static std::wstring LogFile();

	/* Prints a line of '-' characters */
	static VOID hline();

	/* Checks if MTail is already running */
	//static BOOL isMTailRunning();

	/* Start MTail Application */
	//static VOID startMTail();
};