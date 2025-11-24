#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[30], n, head, i, j, seek = 0, temp, maxRange;
    int direction;

    printf("Enter the maximum range of the disk: ");
    scanf("%d", &maxRange);

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the head movement direction (1 for high, 0 for low): ");
    scanf("%d", &direction);

    // Add boundaries (0, maxRange-1)
    queue[n++] = 0;
    queue[n++] = maxRange - 1;

    // Insert head into queue
    queue[n++] = head;

    // Sort all elements
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(queue[j] > queue[j + 1]) {
                temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    // Find head index
    int index = 0;
    for(i = 0; i < n; i++) {
        if(queue[i] == head) {
            index = i;
            break;
        }
    }

    printf("\nHead Movement Sequence:\n");

    if(direction == 1) {                   // Move right first
        for(i = index; i < n - 1; i++) {
            printf("%d -> ", queue[i]);
            seek += abs(queue[i + 1] - queue[i]);
        }
        for(i = index - 1; i >= 0; i--) {
            printf("%d -> ", queue[i]);
            if(i > 0)
                seek += abs(queue[i] - queue[i - 1]);
        }
    } 
    else {                                 // Move left first
        for(i = index; i > 0; i--) {
            printf("%d -> ", queue[i]);
            seek += abs(queue[i] - queue[i - 1]);
        }
        for(i = index + 1; i < n; i++) {
            printf("%d -> ", queue[i]);
            if(i < n - 1)
                seek += abs(queue[i + 1] - queue[i]);
        }
    }

    printf("%d", queue[0]);  // print last element without arrow

    printf("\n\nTotal Head Movement = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / (n - 3));  // only original requests

    return 0;
}

