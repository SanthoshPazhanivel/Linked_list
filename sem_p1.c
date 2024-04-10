/* 
 * This program(process-1) is to illustrate the process synchronization 
 * for the proper access of the common resource between them
 * using semaphore
 * 
 */

#include<stdio.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<fcntl.h>
#define SEM_KEY 5
#define SEM_SET 3
int main() {
	int id,fd;
	struct sembuf v;
	char ch[] = "abcdefghijklmnopqrstuvwxyz";
	id = semget(SEM_KEY,SEM_SET,IPC_CREAT|0644);
	if(id < 0) {
		perror("semget");
		return 0;
	}
	fd = open("temp",O_WRONLY|O_CREAT|O_APPEND,0644);
	if(fd < 0) {
		perror("open");
		return 0;
	}
	v.sem_op = 0;
	v.sem_flg = 0;
	v.sem_num = 0;
	semop(id,&v,1);
	printf("after semop() function..\n");
	sleep(1);
	semctl(id,0,SETVAL,1);
	printf("Process make a lock...\n")
	for(int i=0;ch[i];i++) {
		write(fd,ch+i,1);
		sleep(1);
	}
	semctl(id,0,SETVAL,0);
	printf("lock released..\n");
}
