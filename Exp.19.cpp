#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>   // for intptr_t

pthread_mutex_t lock;
int counter = 0;

void *threadFunc(void *arg) {
    intptr_t id = (intptr_t)arg;   // safely convert pointer back to integer id

    pthread_mutex_lock(&lock);

    counter++;
    printf("Thread %ld entered | Counter = %d\n", (long)id, counter);
    sleep(1);
    printf("Thread %ld exiting\n", (long)id);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t t1, t2, t3;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("mutex init failed");
        return 1;
    }

    pthread_create(&t1, NULL, threadFunc, (void*)(intptr_t)1);
    pthread_create(&t2, NULL, threadFunc, (void*)(intptr_t)2);
    pthread_create(&t3, NULL, threadFunc, (void*)(intptr_t)3);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}

