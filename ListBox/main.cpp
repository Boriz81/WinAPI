#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <Windows.h>
#include "resource.h"


CONST CHAR str_INVITATION[] = "Выберите строку";

CHAR string_1[] = { "Строка №0" };
CHAR string_2[] = { "Строка №1" };
CHAR string_3[] = { "Строка №2" };
CHAR string_4[] = { "Строка №3" };
CHAR string_5[] = { "Строка №4" };
CHAR string_6[] = { "Строка №5" };

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCMDLine, INT nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);

		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)string_1);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)string_2);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)string_3);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)string_4);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)string_5);
		SendMessage(hCombo, CB_ADDSTRING, 0, (LPARAM)string_6);
		
		SendMessage(hCombo, WM_SETTEXT, 0, (LPARAM)str_INVITATION);
		

	}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			CONST INT SIZE = 256;
			CHAR sz_buffer[SIZE] = {};
			HWND hCombo = GetDlgItem(hwnd, IDC_COMBO1);
			HWND hList = GetDlgItem(hwnd, IDC_LIST3);
			int i = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			SendMessage(hCombo, CB_GETLBTEXT, i, (LPARAM)sz_buffer);
			SendMessage(hList, LB_ADDSTRING, i, (LPARAM)sz_buffer);
			CHAR sz_message[SIZE]{};
			sprintf(sz_message, "Вы выбрали № %i, со значением \"%s\"", i, sz_buffer);
			MessageBox(hwnd, sz_message, "Info", MB_OK | MB_ICONINFORMATION);
		}
		break;
		case IDCANCEL: EndDialog(hwnd, 0);
		}
		break;
	case WM_CLOSE:EndDialog(hwnd, 0);
	}
	return FALSE;

}