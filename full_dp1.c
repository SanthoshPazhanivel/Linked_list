/*
 * This progrom is to illustrate the full-duplex 
 * communication using the message queue and thread 
 * concept.
 *
 * Here full_duplex1 is considered as the one-end of
 * the communication, where it can send and receive the 
 * data of Max length
 */

#include<stdio.h>
#include<sys/msg.h>
#include<string.h>
#include<pthread.h>
#define MAX 50

struct msgbuf {
	long mtype;
	char mtext[MAX];
}v,v1;
int id,id1;
				// send a message...
void* thread1(void *p) {
	while(1) {
		v.mtype = 1;
		scanf(" %[^\n]",v.mtext);
		msgsnd(id,&v,strlen(v.mtext)+1,0);
	}
	pthread_exit(0);
}
				// receive a message
void *thread2(void *p) {
	while(1) {
		msgrcv(id1,&v1,sizeof(v1.mtext),0,0);
		printf("%s\n",v1.mtext);
	}
	pthread_exit(0);
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
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);	
}
