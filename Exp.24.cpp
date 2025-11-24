#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char write_buf[] = "This is OS file system call test.\n";
    char read_buf[100];

    fd = open("testfile.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    write(fd, write_buf, strlen(write_buf));

    lseek(fd, 0, SEEK_SET);

    // Clear buffer before reading
    memset(read_buf, 0, sizeof(read_buf));

    read(fd, read_buf, sizeof(read_buf) - 1);

    printf("Data read from file:\n%s", read_buf);

    close(fd);
    return 0;
}

