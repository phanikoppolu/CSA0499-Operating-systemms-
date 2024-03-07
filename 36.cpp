#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 1024
#define MAX_BLOCKS 100 
struct DiskBlock {
int blockID;
char data[BLOCK_SIZE];
struct DiskBlock* nextBlock;
};
struct File {
struct DiskBlock* firstBlock; 
struct DiskBlock* lastBlock; 
};
struct DiskBlock* createDiskBlock(int blockID, char* data) {
struct DiskBlock* newBlock = (struct DiskBlock*)malloc(sizeof(struct DiskBlock));
newBlock->blockID = blockID;
sprintf(newBlock->data, "%s", data);
newBlock->nextBlock = NULL;
return newBlock;
}
struct File* createFile(struct DiskBlock* firstBlock, struct DiskBlock* lastBlock) {
struct File* newFile = (struct File*)malloc(sizeof(struct File));
newFile->firstBlock = firstBlock;
newFile->lastBlock = lastBlock;
return newFile;
}
void readDiskBlock(struct DiskBlock* block) {
printf("Reading Block %d:\n", block->blockID);
printf("Data: %s\n", block->data);
}
void readFile(struct File* file) {
struct DiskBlock* currentBlock = file->firstBlock;
while (currentBlock != NULL) {
readDiskBlock(currentBlock);
currentBlock = currentBlock->nextBlock;
}
}
int main() {
struct DiskBlock* blocks[MAX_BLOCKS]; 
struct File* file; 
int numBlocks = 0;
printf("Creating and writing blocks to the disk...\n");
for (int i = 0; i < 5; i++) {
blocks[numBlocks++] = createDiskBlock(i,"This is block data");
}
printf("\nCreating file...\n");
file = createFile(blocks[0], blocks[4]); 
printf("\nReading file...\n");
readFile(file);
for (int i = 0; i < numBlocks; i++) {
free(blocks[i]);
}
free(file);
return 0;
}

