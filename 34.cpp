#include <stdio.h>
#include <stdlib.h>
#define RECORD_SIZE 50 
#define MAX_RECORDS 100
struct Record {
int recordID;
char data[RECORD_SIZE];
};
void readRecord(struct Record records[], int recordNum) {
printf("Reading Record %d:\n", recordNum);
printf("Record ID: %d\n", records[recordNum].recordID);
printf("Data: %s\n", records[recordNum].data);
}
int main() {
struct Record records[MAX_RECORDS]; 
int numRecords = 0; 
printf("Creating and writing records to the file system...\n");
for (int i = 0; i < 5; i++) {
struct Record newRecord;
newRecord.recordID = numRecords;
sprintf(newRecord.data, "This is Record %d", numRecords);
records[numRecords++] = newRecord;
}
printf("\nReading records from the file system...\n");
for (int i = 0; i < numRecords; i++) {
readRecord(records, i);
}
return 0;
}

