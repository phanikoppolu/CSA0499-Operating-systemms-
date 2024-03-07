#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define NUM_PRODUCERS 2
#define NUM_CONSUMERS 3
int buffer[BUFFER_SIZE];
sem_t empty, full;
pthread_mutex_t mutex;
void *producer(void *arg) {
int item = 0;
while (1) {
sleep(1);
sem_wait(&empty);
pthread_mutex_lock(&mutex);
buffer[item] = rand() % 100;
printf("Produced item: %d\n", buffer[item]);
item = (item + 1) % BUFFER_SIZE;
pthread_mutex_unlock(&mutex);
sem_post(&full);
}
}
void *consumer(void *arg) {
int item = 0;
while (1) {
sleep(1);
sem_wait(&full);
pthread_mutex_lock(&mutex);n
printf("Consumed item: %d\n", buffer[item]);
buffer[item] = 0;
item = (item + 1) % BUFFER_SIZE;
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}
}
int main() {
pthread_t producers[NUM_PRODUCERS], consumers[NUM_CONSUMERS];
sem_init(&empty, 0, BUFFER_SIZE);
sem_init(&full, 0, 0);
pthread_mutex_init(&mutex, NULL);
for (int i = 0; i < NUM_PRODUCERS; i++) {
pthread_create(&producers[i], NULL, producer, NULL);
}
for (int i = 0; i < NUM_CONSUMERS; i++) {
pthread_create(&consumers[i], NULL, consumer, NULL);
}
for (int i = 0; i < NUM_PRODUCERS; i++) {
pthread_join(producers[i], NULL);
}
for (int i = 0; i < NUM_CONSUMERS; i++) {
pthread_join(consumers[i], NULL);
}
sem_destroy(&empty);
sem_destroy(&full);
pthread_mutex_destroy(&mutex);
return 0;
}

