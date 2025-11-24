#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main() {
    int fd;
    struct stat fileStat;
    struct dirent *de;
    DIR *dr;
    char buffer[100];

    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);
    if (fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    write(fd, "OS Lab System Call Test", 23);

    printf("\nFile Descriptor: %d\n", fd);

    // lseek + read
    lseek(fd, 0, SEEK_SET);

    memset(buffer, 0, sizeof(buffer)); // clear buffer
    read(fd, buffer, 23);
    buffer[23] = '\0';  // null-terminate string

    printf("File Content: %s\n", buffer);

    // stat
    if (stat("sample.txt", &fileStat) == 0) {
        printf("File Size: %ld bytes\n", fileStat.st_size);
    } else {
        printf("Error getting file stats\n");
    }

    // Directory listing
    dr = opendir(".");
    if (dr == NULL) {
        printf("Could not open current directory\n");
        return 1;
    }

    printf("\nFiles in Current Directory:\n");
    while ((de = readdir(dr)) != NULL)
        printf("%s\n", de->d_name);

    close(fd);
    closedir(dr);
    return 0;
}

