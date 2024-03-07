#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 3 
#define MAX_PAGES 20 
int isPagePresent(int frames[], int page, int numFrames) {
for (int i = 0; i < numFrames; i++) {
if (frames[i] == page)
return 1;
}
return 0;
}
int findOptimalPage(int pages[], int frames[], int numFrames, int numPages, int index) {
int farthestIndex = -1;
int farthestPage = -1;
for (int i = 0; i < numFrames; i++) {
int j;
for (j = index + 1; j < numPages; j++) {
if (frames[i] == pages[j]) {
if (j > farthestIndex) {
farthestIndex = j;
farthestPage = i;
}
break;
}
}
if (j == numPages)
return i;
}
return farthestPage;
}
int main() {
int frames[MAX_FRAMES]; 
int pages[MAX_PAGES]; 
int pageFaults = 0; 
int numFrames = 0; 
for (int i = 0; i < MAX_FRAMES; i++)
frames[i] = -1;
printf("Enter the reference string (max %d pages, -1 to end): ", MAX_PAGES);
int page, page_count = 0;
while (scanf("%d", &page) && page != -1) {
pages[page_count++] = page;
}
for (int i = 0; i < page_count; i++) {
int page = pages[i];
if (!isPagePresent(frames, page, numFrames)) {
if (numFrames < MAX_FRAMES) {
frames[numFrames++] = page;
} else {
int replaceIndex = findOptimalPage(pages, frames, numFrames, page_count, i);
frames[replaceIndex] = page;
}
pageFaults++;
}
printf("Page %d: ", page);
for (int j = 0; j < numFrames; j++) {
printf("[%d] ", frames[j]);
}
printf("\n");
}
printf("Total Page Faults: %d\n", pageFaults);
return 0;
}

