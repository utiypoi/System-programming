#include <windows.h>
#include <stdio.h>
#include <handleapi.h>

int main(int argc, char* argv[])
{
	DWORD pid_id = GetCurrentProcessId();
	printf("Current process ID:  %d\n", pid_id); //1
	HANDLE handle_proc = GetCurrentProcess();
	printf("Pseudo-handle of the current process:  %d\n", handle_proc); //2
	HANDLE handle_dub, hThread;
	DWORD dwThreadId;
	DuplicateHandle(GetCurrentProcess(), handle_proc, GetCurrentProcess(), &handle_dub, 0, FALSE, DUPLICATE_SAME_ACCESS);
	printf("Copy of current process handle: %d\n", handle_dub); //3
	CloseHandle(handle_proc); //5
	HANDLE proc_open = OpenProcess(PROCESS_ALL_ACCESS, TRUE, pid_id); 
	printf("Handle to the current process: %d\n", proc_open); //4
	CloseHandle(proc_open); //6
	system("pause");
}