#include <stdio.h>
int main() {
    int i, j, n, frames, faults = 0, next = 0;
    int pages[50], frame[10];
    
    printf("FIFO Page Replacement Simulation\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage Reference -> Frames\n");

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frame[next] = page;
            next = (next + 1) % frames;
            faults++;
        }
		printf("%2d -> ", page);
        for (j = 0; j < frames; j++) {
            if (frame[j] == -1)
                printf(" - ");
            else
                printf("%2d ", frame[j]);
        }
        printf("\n");
    }
    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

