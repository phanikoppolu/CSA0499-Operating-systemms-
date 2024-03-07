#include<stdio.h>
#define MAX_FRAMES 3 
#define MAX_PAGES 20 
int main() {
int frames[MAX_FRAMES]; 
int pages[MAX_PAGES]; 
int pageFaults = 0; 
int frameIndex = 0; 
for(int i = 0; i < MAX_FRAMES; i++)
frames[i] = -1;
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
break;
}
}
if(!pageFound) {
frames[frameIndex] = page;
frameIndex = (frameIndex + 1) % MAX_FRAMES; // Circular increment
pageFaults++;
}
printf("Page %d: ", page);
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

