#include <stdio.h>

int main() {
    int blockSize[20], processSize[20], allocation[20];
    int blockNum, processNum;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blockNum);

    printf("Enter size of each block:\n");
    for (int i = 0; i < blockNum; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &processNum);

    printf("Enter size of each process:\n");
    for (int i = 0; i < processNum; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Initially no process is allocated
    for (int i = 0; i < processNum; i++)
        allocation[i] = -1;

    // Worst Fit Allocation Logic
    for (int i = 0; i < processNum; i++) {
        int worstIndex = -1;

        for (int j = 0; j < blockNum; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIndex == -1 || blockSize[j] > blockSize[worstIndex])
                    worstIndex = j;
            }
        }

        if (worstIndex != -1) {
            allocation[i] = worstIndex;
            blockSize[worstIndex] -= processSize[i];
        }
    }

    // Output Allocation Results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < processNum; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

