#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t t1, t2;

void* run1(void *arg) {
    printf("Thread1 running\n");
    pthread_exit(NULL);
}

void* run2(void *arg) {
    printf("Thread2 running\n");

    // Compare thread IDs correctly
    if (pthread_equal(t2, pthread_self()))
        printf("This is Thread2\n");
    else
        printf("This is not Thread2\n");

    pthread_exit(NULL);
}

int main() {
    pthread_create(&t1, NULL, run1, NULL);
    pthread_create(&t2, NULL, run2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread done\n");
    return 0;
}

