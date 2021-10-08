#include <windows.h>

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)

WCHAR		WindowClass[MAX_NAME_STRING];
WCHAR		WindowTitle[MAX_NAME_STRING];
INT			WindowHeight;
INT			WindowWidth;

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {

	/* - Initialize Global Variables - */

	wcscpy_s(WindowClass, TEXT("EngineClass")); //wcscpy_s is for using WCHAR
	wcscpy_s(WindowTitle, TEXT("FACEngine"));

	WindowWidth = 1366;
	WindowHeight = 768;

	/* - Create Window Class - */

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); //Class size
	wcex.style = CS_HREDRAW | CS_VREDRAW; //Redraw horizontally and vertically at start
	wcex.cbClsExtra = 0; //Extra memory
	wcex.cbWndExtra = 0; //Extra memory

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Cursor (IDC_ARROW -> Default arrow)
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); //Background (NULL_BRUSH -> White bg)

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION); //Top-left corner icon
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION); //Taskbar icon

	wcex.lpszClassName = WindowClass;

	wcex.lpszMenuName = nullptr; //No menu in the window

	wcex.hInstance = HInstance(); //Reference to the instance of the program that's running

	wcex.lpfnWndProc = DefWindowProc; //How the window will perform as in button interactions and such

	RegisterClassEx(&wcex);

	/* - Create and Display our Window - */

	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, WindowWidth, WindowHeight, nullptr, nullptr, HInstance(), nullptr);
		//hWnd stands for "Window Handler", and it's a representation of the entire Window
		//CreateWindow(className, title, style, x_location, y_location, width, height, parent_window, menu, hInstance, ???)

	if (!hWnd) {
		//Handler in case CreateWindow fails
		MessageBox(0, L"Failed to Create Window!.", 0, 0);
		return 0;
	}

	ShowWindow(hWnd, SW_SHOW);

	/* - Listen for Message events - */

	MSG msg = { 0 };
	while (msg.message != WM_QUIT) {
		//If there are Window messages, process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return 0;
}