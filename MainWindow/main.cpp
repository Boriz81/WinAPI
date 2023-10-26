#include <cstdio>	
#include<Windows.h>
#include"resource.h"

CONST CHAR g_sz_WINDOW_CLASS[] = "My Window Class "; // Имя класса окна

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, INT nCmdShow)
{
	//-------------// 1) Регистрация класса окна:
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(wc));
	
	wc.cbSize = sizeof(wc);
	//cb - Count
	wc.cbWndExtra = 0; 
	wc.cbClsExtra = 0;
	wc.style = 0;

	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_CPU));
	wc.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON_RAM));
	wc.hCursor = LoadIcon(NULL, IDC_ARROW);
	wc.hbrBackground = HBRUSH(COLOR_WINDOW + 1);

	wc.hInstance = hInstance;
	// Фунция WinMain() принимает hInstance как параметр, и поэтому к нему есть прямой доступ
	// В любой дркгой функции 'hInstance' всегда можно получить при помощи функции 
	wc.lpfnWndProc = WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_sz_WINDOW_CLASS;

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Class registration failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	//-------------// 2) Создание окна:
	HWND hwnd = CreateWindowEx
	(
		NULL, //ExStyle
		g_sz_WINDOW_CLASS, //Class name
		g_sz_WINDOW_CLASS, //Window name
		WS_OVERLAPPEDWINDOW, // У главного окна всегда будет такой стиль
		CW_USEDEFAULT, CW_USEDEFAULT, //Position - Положение окна на экране
		CW_USEDEFAULT, CW_USEDEFAULT, //Size - Размер окна
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window creation failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	//-------------// 3) Запуск цикла сообщений:
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	case WM_COMMAND:
		break;
	case WM_DESTROY:PostQuitMessage(0);break;
	case WM_CLOSE:	DestroyWindow(hwnd); break;
	default:		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return NULL;
}