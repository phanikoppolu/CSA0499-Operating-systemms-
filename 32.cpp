#include<stdio.h>
#define MAX_FRAMES 3 
#define MAX_PAGES 20 
int main() {
int frames[MAX_FRAMES]; 
int pages[MAX_PAGES];
int pageFaults = 0;
int counter[MAX_FRAMES];
int leastUsed = 0; 
for(int i = 0; i < MAX_FRAMES; i++) {
frames[i] = -1;
counter[i] = 0;
}
printf("Enter the reference string (max %d pages, -1 to end): ", MAX_PAGES);
int page, page_count = 0;
while (scanf("%d", &page) && page != -1) {
pages[page_count++] = page;
}
for(int i = 0; i < page_count; i++) {
int page = pages[i];
int pageFound = 0;
for(int j = 0; j < MAX_FRAMES; j++) {
if(frames[j] == page) {
pageFound = 1;
counter[j] = i + 1;
break;
}
}
if(!pageFound) {
leastUsed = 0;
for(int j = 1; j < MAX_FRAMES; j++) {
if(counter[j] < counter[leastUsed])
leastUsed = j;
}
frames[leastUsed] = page;
counter[leastUsed] = i + 1; 
pageFaults++;
}
for(int j = 0; j < MAX_FRAMES; j++) {
if(frames[j] == -1)
printf("[ ] ");
else
printf("[%d] ", frames[j]);
}
printf("\n");
}
printf("Total Page Faults: %d\n", pageFaults);
return 0;
}

