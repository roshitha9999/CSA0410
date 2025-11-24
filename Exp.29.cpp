#include <stdio.h>
#include <stdlib.h>

// Global variables
int mutex = 1;   // Controls access (binary semaphore)
int full = 0;    // Counts full slots
int empty = 3;   // Counts empty slots (Buffer size = 3)
int item = 0;    // Item counter

// Function declarations
int wait(int);
int signal(int);
void producer();
void consumer();

int main() {
    int choice;
    printf("\n--- CLASSICAL PROCESS SYNCHRONIZATION PROBLEM ---\n");
    printf("Producer-Consumer Simulation using Semaphores\n");

    while (1) {
        printf("\n1. Produce Item\n2. Consume Item\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("? Buffer is full! Producer is waiting...\n");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("? Buffer is empty! Consumer is waiting...\n");
                break;

            case 3:
                printf("Exiting simulation...\n");
                exit(0);

            default:
                printf("? Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Wait operation
int wait(int s) {
    return (--s);
}

// Signal operation
int signal(int s) {
    return (++s);
}

// Producer process
void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    item++;
    printf("? Producer produced item %d\n", item);
    mutex = signal(mutex);
}

// Consumer process
void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("?? Consumer consumed item %d\n", item);
    item--;
    mutex = signal(mutex);
}

