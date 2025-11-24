#include <stdio.h>
#include <stdlib.h>

struct File {
    char name[20];
    int start, end, length;
    int blocks[50];
};

int main() {
    struct File files[10];
    int disk[50] = {0};  // 0 = free, 1 = allocated
    int n, i, j, k, block;

    printf("Enter number of files to allocate: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid number of files.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {

        printf("\nEnter file name: ");
        scanf("%s", files[i].name);

        printf("Enter number of blocks required: ");
        scanf("%d", &files[i].length);

        if (files[i].length <= 0 || files[i].length > 50) {
            printf("Invalid file length.\n");
            i--;
            continue;
        }

        printf("Enter starting block (0-49): ");
        scanf("%d", &files[i].start);

        // Validate start block
        if (files[i].start < 0 || files[i].start >= 50) {
            printf("Invalid starting block! Must be between 0 and 49.\n");
            i--;
            continue;
        }

        if (disk[files[i].start] == 1) {
            printf("Starting block already allocated! Choose another block.\n");
            i--;
            continue;
        }

        // Allocate starting block
        files[i].blocks[0] = files[i].start;
        disk[files[i].start] = 1;
        k = 1;

        // Allocate remaining blocks
        for (j = 1; j < files[i].length; j++) {
            printf("Enter next block number for the file (0-49): ");
            scanf("%d", &block);

            if (block < 0 || block >= 50) {
                printf("Invalid block number! Must be 0-49.\n");
                j--;
                continue;
            }

            if (disk[block] == 0) {
                files[i].blocks[k++] = block;
                disk[block] = 1;
            } else {
                printf("Block %d already allocated! Enter a different block.\n", block);
                j--; // retry same block
            }
        }

        // Last block becomes end block
        files[i].end = files[i].blocks[k - 1];

        // Display result
        printf("\nFile '%s' allocated successfully!\n", files[i].name);
        printf("Start Block: %d\n", files[i].start);
        printf("End Block: %d\n", files[i].end);
        printf("Blocks Linked: ");

        for (j = 0; j < files[i].length; j++) {
            if (j == files[i].length - 1)
                printf("%d -> NULL", files[i].blocks[j]);
            else
                printf("%d -> ", files[i].blocks[j]);
        }
        printf("\n");
    }

    // Display File Allocation Table
    printf("\n\nFile Allocation Table:\n");
    printf("------------------------------------------\n");
    printf("File Name\tStart\tEnd\tAllocated Blocks\n");
    printf("------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%s\t\t%d\t%d\t", files[i].name, files[i].start, files[i].end);
        for (j = 0; j < files[i].length; j++) {
            printf("%d ", files[i].blocks[j]);
        }
        printf("\n");
    }

    // Display Disk Status
    printf("\nDisk Block Status (1 = Allocated, 0 = Free):\n");
    for (i = 0; i < 50; i++) {
        printf("%d ", disk[i]);
    }
    printf("\n");

    return 0;
}

