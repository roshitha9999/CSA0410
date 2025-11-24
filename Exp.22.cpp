#include <stdio.h>

int main() {
    int blockSize[20], processSize[20], allocation[20];
    int blockNum, processNum;

    printf("Enter number of blocks: ");
    scanf("%d", &blockNum);

    printf("Enter block sizes:\n");
    for (int i = 0; i < blockNum; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &processNum);

    printf("Enter process sizes:\n");
    for (int i = 0; i < processNum; i++)
        scanf("%d", &processSize[i]);

    // Initialize allocation array
    for (int i = 0; i < processNum; i++)
        allocation[i] = -1;

    // Best Fit Algorithm
    for (int i = 0; i < processNum; i++) {
        int bestIdx = -1;

        for (int j = 0; j < blockNum; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
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

