#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

void* threadFunc(void* arg)
{
	printf("In NEW Thread \n");

}


int main()
{
	pthread_t tid;  // a thread id, Performation a struct

	/*
	 first  param: performation thread id, must a pthread_t point type
	 second param: performation thread attributer it is a pthread_attr_t type(union)
	 third  param: mean executor content, neeed a function point
	 four   param: performation third param func param, no param, set NULL
	 */
	pthread_create(&tid, NULL, threadFunc, NULL);  // create a thread


	// wait target thread running end
	pthread_join(tid, NULL);

	// print main thread flag
	printf("This is main thread print \n");

	return 0;

}

