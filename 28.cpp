#include <stdio.h>  
#include <sys/ipc.h>  
#include <sys/msg.h>  
MARRI LAXMAN REDDY INSTITUTE OF TECHNOLOGY AND MANAGEMENT 
OPERATING  
SYSTEMS LAB MANUAL 
Dept. of CSE 46 
struct mesg_buffer {  
long mesg_type;  
char mesg_text[100];  
} message;  
int main()  
{  
key_t key;  
int msgid;  
key = ftok("progfile", 65);  
msgid = msgget(key, 0666 | IPC_CREAT);
msgrcv(msgid, &message, sizeof(message), 1, 0); 
printf("Data Received is : %s \n",  
message.mesg_text);  
msgctl(msgid, IPC_RMID, NULL);  
return 0;  
}
