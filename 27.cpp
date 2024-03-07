#include <stdio.h>  
#include <sys/ipc.h>  
#include <sys/msg.h>   
struct mesg_buffer {  
long mesg_type;  
char mesg_text[100];  
} message;  
int main()  
{  
key_t key;  
int msgid;  
key = ftok("progfile", 65); AT);  
message.mesg_type = 1;  
printf("Write Data : ");  
msgid = msgget(key, 0666 | IPC_CRE
gets(message.mesg_text);  
msgsnd(msgid, &message, sizeof(message), 0);  
printf("Data send is : %s \n", message.mesg_text);  
return 0; 
}
