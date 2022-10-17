#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#pragma warning(disable : 4996)

int main()
{
    char buffer[256];
    DWORD size = 256;
    GetComputerNameA(buffer, &size);
    printf("%s\n", buffer);
    TCHAR sysDirectory[MAX_PATH];
    GetSystemDirectory(sysDirectory, MAX_PATH);
    printf("%s\n", sysDirectory);
    OSVERSIONINFO osVersion;
    ZeroMemory(&osVersion, sizeof(OSVERSIONINFOEX));
    osVersion.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((OSVERSIONINFO*)&osVersion);
    printf("%u.%u\n", osVersion.dwMajorVersion, osVersion.dwMinorVersion);
}
