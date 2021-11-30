
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

