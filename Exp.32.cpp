#include <stdio.h>
int main() {
    int n, frames, pages[50], frame[10], counter[10];
    int i, j, k, faults = 0, time = 0, min, pos;

    printf("LRU Page Replacement Simulation\n");
    printf("Enter number of pages: ");
    scanf("%d", &n);
	printf("Enter the page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        frame[i] = -1;   
        counter[i] = 0;  
    }
	printf("\nPage Reference -> Frames\n");

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                counter[j] = ++time; 
                break;
            }
        }
        if (!found) {
            pos = 0;
            min = counter[0];
            for (j = 1; j < frames; j++) {
                if (counter[j] < min) {
                    min = counter[j];
                    pos = j;
                }
            }
            frame[pos] = page;
            counter[pos] = ++time;
            faults++;
        }
        printf("%2d -> ", page);
        for (k = 0; k < frames; k++) {
            if (frame[k] == -1)
                printf(" - ");
            else
                printf("%2d ", frame[k]);
        }
        printf("\n");
    }
	printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}

