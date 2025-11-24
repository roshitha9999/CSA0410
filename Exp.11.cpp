#include <stdio.h>
#include <pthread.h>

void* threadFunction(void* arg) {
    int thread_id = *(int*)arg;
    for(int i = 1; i <= 5; i++) {
        printf("Thread %d prints: %d\n", thread_id, i);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    // Create two threads
    pthread_create(&t1, NULL, threadFunction, &id1);
    pthread_create(&t2, NULL, threadFunction, &id2);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Main thread finished execution.\n");
    return 0;
}
