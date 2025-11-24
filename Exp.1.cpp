#include <windows.h>
#include <stdio.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent Process ID: %lu\n", GetCurrentProcessId());

    // Create a new (child) process
    if(CreateProcess(
        NULL,               // No module name
        "notepad.exe",      // New process to run (child)
        NULL, NULL, FALSE,
        0, NULL, NULL,
        &si, &pi
    )) {
        printf("Child Process created successfully!\n");
        printf("Child Process ID: %lu\n", pi.dwProcessId);
    } else {
        printf("Failed to create child process.\n");
    }

    // Close handles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
