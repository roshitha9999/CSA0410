#include <stdio.h>

int findOptimal(int pages[], int frames[], int n, int index, int m) {
    int pos = -1, farthest = index;
    int i, j;

    for (i = 0; i < m; i++) {
        int found = 0;

        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                found = 1;
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }

        // If frame page is never used again ? replace immediately
        if (found == 0)
            return i;
    }

    // If all pages will be used again, replace the farthest used one
    if (pos == -1)
        return 0;

    return pos;
}

int main() {
    int frames[10], pages[30];
    int n, m, pageFaults = 0;
    int i, j, pos;
    int inFrame, usedEmpty;

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
        inFrame = 0;
        usedEmpty = 0;

        // Check if page already exists
        for (j = 0; j < m; j++) {
            if (frames[j] == pages[i]) {
                inFrame = 1;
                break;
            }
        }

        // Page Fault (page not found)
        if (!inFrame) {

            // Check for empty frame first
            for (j = 0; j < m; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    pageFaults++;
                    usedEmpty = 1;
                    break;
                }
            }

            // No empty frame ? use Optimal Replacement
            if (!usedEmpty) {
                pos = findOptimal(pages, frames, n, i + 1, m);
                frames[pos] = pages[i];
                pageFaults++;
            }
        }

        // Printing Output
        printf("%d\t", pages[i]);
        for (j = 0; j < m; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }

        if (!inFrame)
            printf("\t\tYes");
        else
            printf("\t\tNo");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

