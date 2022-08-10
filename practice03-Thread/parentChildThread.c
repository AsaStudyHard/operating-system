#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>


void* funcThread(void* arg)
{
    // child thread sleep 2 second, parent thread will running end
    sleep(2);
    // main thread executor end, process destroy, so child thread destroy, printf() don't executor
    printf("In NEW Thread \n");


}


int main()
{
    pthread_t tid;

    pthread_create(&tid, NULL, funcThread, NULL);

    printf("tid = %lud \n", tid);

    printf("In main thread \n");

    return 0;
}