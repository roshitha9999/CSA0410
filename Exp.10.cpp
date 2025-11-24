#include <windows.h>
#include <stdio.h>
#include <string.h>
int main() {
    HANDLE hSlot, hFile;
    DWORD read, written;
    char buffer[100];
    hSlot = CreateMailslot(
    "\\\\.\\mailslot\\MyMailslot",
    0,
    MAILSLOT_WAIT_FOREVER,
    NULL
    );
    if (hSlot == INVALID_HANDLE_VALUE) {
    printf("Error creating mailslot\n");
    return 1;
    } 
    hFile = CreateFile(
        "\\\\.\\mailslot\\MyMailslot",
        GENERIC_WRITE,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    ); 
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Error opening mailslot\n");
        return 1;
    }
    printf("Enter message: ");
    fgets(buffer, sizeof(buffer), stdin); 
    buffer[strcspn(buffer, "\n")] = '\0'; 
    WriteFile(hFile, buffer, strlen(buffer) + 1, &written, NULL); 
    ReadFile(hSlot, buffer, sizeof(buffer), &read, NULL);
    printf("Sender sent -> %s | Receiver got -> %s\n", buffer, buffer);
    CloseHandle(hFile);
    CloseHandle(hSlot);
    return 0;
}
