#include <Windows.h>

INT WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInst, LPSTR IpCmdLine, INT nCmdShow)
{
	MessageBox
	(
		NULL, 
		"Hello Windows", 
		"Header (CAPTION)", 
		MB_YESNOCANCEL	| MB_ICONASTERISK | MB_HELP |
		MB_DEFBUTTON3	|
		MB_SYSTEMMODAL	|
		MB_RIGHT		| MB_RTLREADING | 
		MB_SETFOREGROUND 

		
	);
	return 0;
}