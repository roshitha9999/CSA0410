#include <stdio.h>

int main() {
    int frames[10], pages[30];
    int n, m, pageFaults = 0, next = 0;
    int flag1, flag2, i, j;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &m);

    // Initialize all frames as empty
    for (i = 0; i < m; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\tPage Fault\n");

    for (i = 0; i < n; i++) {
        flag1 = 0; 
        flag2 = 0;

        // Check if page is present in frames
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page not found ? page fault
        if (flag1 == 0) {
            frames[next] = pages[i];
            next = (next + 1) % m; // FIFO replacement
            pageFaults++;
        }

        // Print current status
        printf("%d\t", pages[i]);
        for (j = 0; j < m; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        if (flag2 == 0)
            printf("\t\tYes");
        else
            printf("\t\tNo");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

