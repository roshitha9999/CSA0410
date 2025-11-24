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

    // Add boundaries (0 and maxRange-1)
    queue[n++] = 0;
    queue[n++] = maxRange - 1;

    // Sort the requests
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(queue[j] > queue[j + 1]) {
                temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }

    // Find first request higher than head
    int index = n - 1; // default last
    for(i = 0; i < n; i++) {
        if(queue[i] >= head) {
            index = i;
            break;
        }
    }

    printf("\nHead Movement Sequence:\n");

    if(direction == 1) {  // Move towards higher values (Right)
        
        // Move right from head to max
        for(i = index; i < n; i++)
            printf("%d -> ", queue[i]);

        // Jump to 0 and continue
        for(i = 0; i < index; i++)
            printf("%d -> ", queue[i]);

        // Total seek calculation
        seek = (maxRange - 1 - head)           // head ? max
             + (maxRange - 1)                  // max ? 0 jump
             + queue[index - 1];               // 0 ? last request on left
    } 
    else {  // Move towards lower values (Left)

        // Move left from head to 0
        for(i = index - 1; i >= 0; i--)
            printf("%d -> ", queue[i]);

        // Jump to max and continue
        for(i = n - 1; i >= index; i--)
            printf("%d -> ", queue[i]);

        // Total seek calculation
        seek = head                            // head ? 0
             + (maxRange - 1)                  // 0 ? max jump
             + (maxRange - 1 - queue[index]);  // max ? first big request
    }

    printf("\n\nTotal Head Movement = %d\n", seek);
    printf("Average Seek Time = %.2f\n", (float)seek / (n - 2)); // exclude added 0 & max

    return 0;
}

