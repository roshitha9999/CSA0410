#include <windows.h>
#include <stdio.h>

int main() {
    HANDLE hMapFile;
    LPCTSTR pBuf;
    const char *message = "Hello from Parent Process";

    // Create shared memory of 256 bytes
    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use paging file
        NULL,                    
        PAGE_READWRITE,          
        0,                       
        256,                     
        "MySharedMemory");       // Shared memory name

    if (hMapFile == NULL) {
        printf("Error creating shared memory\n");
        return 1;
    }

    // Map memory to process
    pBuf = (LPTSTR) MapViewOfFile(
        hMapFile,               
        FILE_MAP_ALL_ACCESS,    
        0, 0, 256);

    if (pBuf == NULL) {
        printf("Error mapping shared memory\n");
        CloseHandle(hMapFile);
        return 1;
    }

    // Write message (Parent simulation)
    printf("Parent writing to shared memory...\n");
    CopyMemory((PVOID)pBuf, message, strlen(message) + 1);

    // ***** CHILD PROCESS SIMULATION *****
    printf("Child reading from shared memory...\n");
    printf("Message: %s\n", (char*)pBuf);

    // Unmap and close shared memory
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);

    return 0;
}
