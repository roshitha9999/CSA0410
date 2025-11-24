#include <stdio.h>

int findLRU(int time[], int n) {
    int i, min = time[0], pos = 0;
    for (i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], pages[30], time[10];
    int n, m, pageFaults = 0, counter = 0;
    int flag1, flag2, i, j, pos;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\tPage Fault\n");

    for (i = 0; i < n; i++) {
        flag1 = 0;
        flag2 = 0;

        // Check if page already exists
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // If page not found, fill empty frame
        if (flag1 == 0) {
            for (j = 0; j < m; j++) {
                if (frames[j] == -1) {
                    counter++;
                    pageFaults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // No empty frame ? replace LRU
        if (flag1 == 0 && flag2 == 0) {
            pos = findLRU(time, m);
            counter++;
            pageFaults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }

        printf("%d\t", pages[i]);
        for (j = 0; j < m; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        if (flag1 == 0)
            printf("\t\tYes");
        else
            printf("\t\tNo");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}

