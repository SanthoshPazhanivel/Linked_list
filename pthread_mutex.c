/*
 * This program is to illustrate the synchronization 
 * between two sub-thread by using the mutex.
 *
 * Once the thread had a lock on the comman resource another
 * thread can't able to access it, until the thread unlock the resource 
 * which held a lock on it.
 */

#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int g; 		// Here, g is considered as the comman resource
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* thread_fun1(void *p) {
	pthread_mutex_lock(&m);
	printf("thread-1 putting lock for the mutex..\n");
	printf("thread-1 g: %d\n",g);
	g=20;
	sleep(1);  
	printf("thread-1 g: %d\n",g);
	printf("changing the g value from the thread-1..\n");
	sleep(1);
	g=100;
	printf("thread-1 g: %d\n",g);
	sleep(1);
	printf("thread-1 unlocking the mutex..\n");
	pthread_mutex_unlock(&m);
	pthread_exit(0);
}
void* thread_fun2(void *p) {
	pthread_mutex_lock(&m);
	printf("thread-2 putting lock for the mutex..\n");
	printf("thread-2 g: %d\n",g);
	printf("thread-2 changing the value of g..\n");
	g=30;
	printf("thread-2 g: %d\n",g);
	sleep(1);
	printf("thread-2 unlocking the mutex..\n");
	pthread_mutex_unlock(&m);
	pthread_exit(0);

}
int main() {
	pthread_t t1,t2;
	pthread_create(&t1,0,thread_fun1,NULL);
	pthread_create(&t2,0,thread_fun2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
}
