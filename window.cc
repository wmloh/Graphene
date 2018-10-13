#include <windows.h>
#include <iostream>

//http://cecilsunkure.blogspot.com/2011/11/windows-console-game-writing-to-console.html

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

HWND textfield, button;

char szClassName[] = "Class Name";

int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR args	, int nCmdShow) {

	HWND hwnd;
	MSG messages;
	WNDCLASSEX wincl;

	// Windows structure
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof(WNDCLASSEX);

	// Use default icon and mouse-pointer
	wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wincl.lpszMenuName = "Program";
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;

	// Window background
	wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

	if(!RegisterClassEx(&wincl)) return -1;
	char s[] = "a";
	hwnd = CreateWindowEx(0, szClassName, s, WS_MINIMIZEBOX | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, 
		500, 500, HWND_DESKTOP, NULL, hThisInstance, NULL);

	ShowWindow(hwnd, nCmdShow);

	while(GetMessage(&messages, NULL, 0, 0)) {
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}

	return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch(message) { // message handlers
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_CREATE:
			textfield = CreateWindow("STATIC", "Hello World!", WS_VISIBLE | WS_CHILD, 20, 20, 100, 20, hwnd, NULL, NULL, NULL);
			button = CreateWindow("BUTTON", "This is a button", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 50, 200, 20, hwnd, (HMENU) 1, NULL, NULL);
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case 1:
					//::MessageBeep(MB_ICONERROR);
					::MessageBox(hwnd, "beep!", "beep2!", MB_OK);
					break;
			}
		case WM_PAINT:
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hwnd, &ps);
			MoveToEx(hdc, 0, 0, NULL);
			//LineTo(hdc, 50, 50);
			EndPaint(hwnd, &ps);
			break;
		default:
			return DefWindowProcW(hwnd, message, wParam, lParam);
	}
	return 0;
}

#if 0
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args	, int ncmdshow) {

	HWND hwnd;

	WNDCLASSW wc = {0};
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;

	if(!RegisterClassW(&wc)) return -1;

	CreateWindowW(L"myWindowClass", L"My Window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

	MSG msg = {0};

	while(GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
#endif