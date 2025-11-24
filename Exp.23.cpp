#include <stdio.h>

int main() {
    int blockSize[20], processSize[20], blockNum, processNum, allocation[20];

    printf("Enter number of blocks: ");
    scanf("%d", &blockNum);

    printf("Enter block sizes:\n");
    for (int i = 0; i < blockNum; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processNum);

    printf("Enter process sizes:\n");
    for (int i = 0; i < processNum; i++) {
        scanf("%d", &processSize[i]);
    }

    // Initialize all allocations to -1
    for (int i = 0; i < processNum; i++) {
        allocation[i] = -1;
    }

    // First Fit Logic
    for (int i = 0; i < processNum; i++) {
        for (int j = 0; j < blockNum; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;              // allocate block j to process i
                blockSize[j] -= processSize[i]; // reduce block size
                break;
            }
        }
    }

    // Output
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (int i = 0; i < processNum; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

