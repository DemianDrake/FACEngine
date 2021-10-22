#include "pch.h"
/* ----------------------------------------------------------- */
/*  Filename: WinMain.cpp                                      */
/*  Author: Damián Ibarra Z. (aka Demian Drake)                */
/*  Licence: MIT Licence                                       */
/* ----------------------------------------------------------- */


/* ----------------------------------------------------------- */
/*  Global Variables                                           */
/* ----------------------------------------------------------- */
#pragma region GlobalVariables

WCHAR		WindowClass[MAX_NAME_STRING];
WCHAR		WindowTitle[MAX_NAME_STRING];
INT			WindowHeight;
INT			WindowWidth;
HICON		hIcon;

#pragma endregion
/* ----------------------------------------------------------- */


/* ----------------------------------------------------------- */
/*  Function Declarations                                      */
/* ----------------------------------------------------------- */
#pragma region FunctionDeclarations

VOID initializeVariables();
VOID createWindowClass();
VOID initializeWindow();
VOID messageLoop();
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam);

#pragma endregion
/* ----------------------------------------------------------- */


/* ----------------------------------------------------------- */
/*  System Operations                                          */
/* ----------------------------------------------------------- */
#pragma region Operations
/*
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
	initializeVariables();
	createWindowClass();
	initializeWindow();
	messageLoop();

	return 0;
}
*/
LRESULT CALLBACK WindowProcess(HWND hWnd, UINT message, WPARAM wparam, LPARAM lparam) {
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hWnd, message, wparam, lparam);
}

#pragma endregion
/* ----------------------------------------------------------- */


/* ----------------------------------------------------------- */
/*  Function Definitions                                       */
/* ----------------------------------------------------------- */
#pragma region FunctionDefinitions

VOID initializeVariables() {
	LoadString(HInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);
	LoadString(HInstance(), IDS_WINDOWTITLE, WindowTitle, MAX_NAME_STRING);

	WindowWidth = 1366;
	WindowHeight = 768;

	hIcon = LoadIcon(HInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

VOID createWindowClass() {
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); //Class size
	wcex.style = CS_HREDRAW | CS_VREDRAW; //Redraw horizontally and vertically at start
	wcex.cbClsExtra = 0; //Extra memory
	wcex.cbWndExtra = 0; //Extra memory

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Cursor (IDC_ARROW -> Default arrow)
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //Background (NULL_BRUSH -> White bg)

	wcex.hIcon = hIcon; //Top-left corner icon
	wcex.hIconSm = hIcon; //Taskbar icon

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr; //No menu in the window

	wcex.hInstance = HInstance(); //Reference to the instance of the program that's running

	wcex.lpfnWndProc = WindowProcess; //How the window will perform as in button interactions and such

	RegisterClassEx(&wcex);
}

VOID initializeWindow() {
	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
	//hWnd stands for "Window Handler", and it's a representation of the entire Window
	//CreateWindow(className, title, style, x_location, y_location, width, height, parent_window, menu, hInstance, ???)

	if (!hWnd) {
		//Handler in case CreateWindow fails
		MessageBox(0, L"Failed to Create Window!.", 0, 0);
		PostQuitMessage(0);
	}

	ShowWindow(hWnd, SW_SHOW);
}

VOID messageLoop() {
	MSG msg = { 0 };
	while (msg.message != WM_QUIT) {
		//If there are Window messages, process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

#pragma endregion
/* ----------------------------------------------------------- */