#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, total = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nDisk Request Sequence: ");
    for(i = 0; i < n; i++)
        printf("%d ", queue[i]);

    printf("\n\nHead Movement Sequence:\n");
    for(i = 0; i < n; i++) {
        printf("Head moves from %d to %d\n", head, queue[i]);
        total += abs(queue[i] - head);
        head = queue[i];
    }

    printf("\nTotal Head Movement = %d\n", total);
    printf("Average Seek Time = %.2f\n", (float)total / n);

    return 0;
}

