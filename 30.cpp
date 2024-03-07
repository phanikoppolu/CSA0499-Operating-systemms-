#include <stdio.h>
#include <pthread.h>
void *thread_function(void *arg) {
printf("Thread created successfully!\n");
return NULL;
}
int main() {
pthread_t tid1, tid2; 
if (pthread_create(&tid1, NULL, thread_function, NULL) != 0) {
fprintf(stderr, "Failed to create thread 1\n");
return 1;
}
if (pthread_create(&tid2, NULL, thread_function, NULL) != 0) {
fprintf(stderr, "Failed to create thread 2\n");
return 1;
}
if (pthread_equal(tid1, tid2))
printf("Threads are equal\n");
else
printf("Threads are not equal\n");

return 0;
}

