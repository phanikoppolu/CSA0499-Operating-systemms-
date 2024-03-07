#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 1024 
#define MAX_BLOCKS 100 
#define MAX_INDEX_ENTRIES 100 
struct Block {
int blockID;
char data[BLOCK_SIZE];
};
struct IndexBlock {
int indexID;
int blockPointers[MAX_INDEX_ENTRIES];
};
void readBlock(struct Block blocks[], int blockNum) {
printf("Reading Block %d:\n", blockNum);
printf("Block ID: %d\n", blocks[blockNum].blockID);
printf("Data: %s\n", blocks[blockNum].data);
}
int main() {
struct Block blocks[MAX_BLOCKS];
struct IndexBlock indexBlock; 
int numBlocks = 0;
printf("Creating and writing blocks to the file system...\n");
for (int i = 0; i < 5; i++) {
struct Block newBlock;
newBlock.blockID = numBlocks;
sprintf(newBlock.data, "This is Block %d", numBlocks);
blocks[numBlocks++] = newBlock;
}
printf("\nCreating index block...\n");
indexBlock.indexID = 0;
for (int i = 0; i < numBlocks; i++) {
indexBlock.blockPointers[i] = i;
}
printf("\nReading blocks using index block...\n");
for (int i = 0; i < numBlocks; i++) {
readBlock(blocks, indexBlock.blockPointers[i]);
}
return 0;
}

