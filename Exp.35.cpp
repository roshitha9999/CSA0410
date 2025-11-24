#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, indexBlock, fileBlocks, i;
    int blocks[50]; // 0 = free, 1 = allocated

    // Initialize disk blocks
    printf("Enter the total number of disk blocks (max 50): ");
    scanf("%d", &n);

    if (n < 1 || n > 50) {
        printf("Invalid number of blocks.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        blocks[i] = 0; // all blocks free
    }

    // Choose index block
    printf("Enter the index block number (0 to %d): ", n - 1);
    scanf("%d", &indexBlock);

    if (indexBlock < 0 || indexBlock >= n) {
        printf("Invalid index block.\n");
        return 0;
    }

    if (blocks[indexBlock] == 1) {
        printf("Index block already allocated. Choose another.\n");
        return 0;
    }

    blocks[indexBlock] = 1;  // allocate index block

    // File block count
    printf("Enter the number of blocks required for the file: ");
    scanf("%d", &fileBlocks);

    if (fileBlocks <= 0) {
        printf("Invalid block count.\n");
        return 0;
    }

    int allocated[fileBlocks];

    // Accept block numbers
    printf("Enter the block numbers for the file: ");
    for (i = 0; i < fileBlocks; i++) {
        scanf("%d", &allocated[i]);

        if (allocated[i] < 0 || allocated[i] >= n) {
            printf("Invalid block number %d.\n", allocated[i]);
            return 0;
        }

        if (blocks[allocated[i]] == 1) {
            printf("Block %d is already allocated. Allocation failed.\n", allocated[i]);
            return 0;
        }
    }

    // Allocate blocks
    for (i = 0; i < fileBlocks; i++) {
        blocks[allocated[i]] = 1;
    }

    // Output
    printf("\nFile Indexed Allocation Table:\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Blocks allocated:\n");

    for (i = 0; i < fileBlocks; i++) {
        printf("  %d -> %d\n", indexBlock, allocated[i]);
    }

    printf("\nAllocation successful!\n");
    return 0;
}

