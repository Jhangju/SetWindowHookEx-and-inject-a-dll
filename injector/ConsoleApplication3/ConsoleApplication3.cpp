
#include <iostream>
#include <Windows.h>

int main()
{
	HMODULE library = LoadLibraryA("load.dll");
	HOOKPROC hookProc = (HOOKPROC)GetProcAddress(library, "injext");

	HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, hookProc, library, 0);
	Sleep(5000);
	UnhookWindowsHookEx(hook);

	return 0;
}