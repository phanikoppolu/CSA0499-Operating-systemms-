#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 100 
int calculateSeekTime(int requests[], int numRequests, int headPosition) {
int totalSeekTime = 0;
int currentHeadPosition = headPosition;
for (int i = 0; i < numRequests; i++) {
totalSeekTime += abs(requests[i] - currentHeadPosition);
currentHeadPosition = requests[i];
}
return totalSeekTime;
}
int main() {
int requests[MAX_REQUESTS];  
int numRequests; 
int headPosition; 
printf("Enter the number of disk requests: ");
scanf("%d", &numRequests);
printf("Enter the disk requests: ");
for (int i = 0; i < numRequests; i++) {
scanf("%d", &requests[i]);
}
printf("Enter the initial position of the disk head: ");
scanf("%d", &headPosition);
int totalSeekTime = calculateSeekTime(requests, numRequests, headPosition);
printf("Total seek time using FCFS algorithm: %d\n", totalSeekTime);
return 0;
}

