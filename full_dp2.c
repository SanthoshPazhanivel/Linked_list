#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<pthread.h>
struct msgbuf {
	long mtype;
	char mtext[20];
}v,v1;
int id,id1;
			// send a message...
void* thread1(void *p) {
	while(1) {
		v.mtype =1;
		scanf(" %[^\n]",v.mtext);
		msgsnd(id1,&v,strlen(v.mtext)+1,0);
	}
}
			// receive a message
void *thread2(void *p) {
	while(1) {
		msgrcv(id,&v1,sizeof(v1.mtext),0,0);
		printf("%s\n",v1.mtext);
	}
}
int main(int argc,char *argv[]) {
	pthread_t t1,t2;
	id = msgget(5,IPC_CREAT|0644);
	id1 = msgget(6,IPC_CREAT|0644);
	if((id < 0) || (id1 < 0)) {
		perror("msgget");
		return 0;
	}
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	while(1);	
}
