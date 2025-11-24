#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5   // number of philosophers

sem_t forks[N];   // fork semaphores

void *philosopher(void *num) {
    int id = *(int *)num;

    printf("Philosopher %d is thinking.\n", id);
    sleep(1);

    // Pick up forks (left and right)
    sem_wait(&forks[id]);
    sem_wait(&forks[(id + 1) % N]);

    printf("Philosopher %d is eating.\n", id);
    sleep(1);

    // Put down forks
    sem_post(&forks[id]);
    sem_post(&forks[(id + 1) % N]);

    printf("Philosopher %d finished eating.\n", id);

    return NULL;
}

int main() {
    pthread_t ph[N];
    int ids[N];

    // Initialize semaphores (forks)
    for (int i = 0; i < N; i++)
        sem_init(&forks[i], 0, 1);

    // Create philosopher threads
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &ids[i]);
    }

    // Wait for all threads
    for (int i = 0; i < N; i++)
        pthread_join(ph[i], NULL);

    // Destroy semaphores
    for (int i = 0; i < N; i++)
        sem_destroy(&forks[i]);

    printf("Dining Philosophers simulation completed.\n");
    return 0;
}

