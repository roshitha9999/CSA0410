#include <stdio.h>
#include <stdlib.h>

struct File {
    char name[20];
    int start, length;
};

int main() {
    struct File files[10];
    int disk[50] = {0};    // 0 = free, 1 = allocated
    int n, i, j, flag;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        printf("\nEnter file name: ");
        scanf("%s", files[i].name);

        printf("Enter starting block (0-49): ");
        scanf("%d", &files[i].start);

        printf("Enter length (number of blocks): ");
        scanf("%d", &files[i].length);

        // ---- SAFETY CHECK: prevent out-of-range access ----
        if (files[i].start < 0 || 
            files[i].start + files[i].length > 50 ||
            files[i].length <= 0) 
        {
            printf("Invalid range! Enter file again.\n");
            i--;        // retry the same file
            continue;
        }

        // Check if required blocks are free
        flag = 0;
        for (j = files[i].start; j < files[i].start + files[i].length; j++) {
            if (disk[j] == 1) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            // Allocate blocks
            for (j = files[i].start; j < files[i].start + files[i].length; j++) {
                disk[j] = 1;
            }
            printf("File '%s' allocated successfully.\n", files[i].name);
        } 
        else {
            printf("File '%s' cannot be allocated. Blocks already in use!\n", files[i].name);
            i--;    // retry same file
        }
    }

    // Display file allocation table
    printf("\n\nFile Allocation Table:\n");
    printf("--------------------------------------\n");
    printf("File Name\tStart\tLength\tBlocks\n");
    printf("--------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t%d\t", files[i].name, files[i].start, files[i].length);

        for (j = files[i].start; j < files[i].start + files[i].length; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Display disk status
    printf("\nDisk Block Status (1 = Allocated, 0 = Free):\n");
    for (i = 0; i < 50; i++) {
        printf("%d ", disk[i]);
    }
    printf("\n");

    return 0;
}

