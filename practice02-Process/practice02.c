#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>



int main()
{
	
	printf("before fork Process id : %d\n", getpid());

	pid_t cid = 0;

	cid = fork();

	if(cid == 0){
		// progarmming running there, this is process is child process
		for (size_t i = 0; i < 3; ++i){
			printf("hello, current process pid = %d, parent process id = %d\n", getpid(), getppid());
			// wait(1);  wait child process to die
			// sleep Process sleep unit s
			// usleep process sleep unit us

			// we see alternate output 
			// usleep(100);

		}
	}else{
		for(size_t i = 0; i < 3; ++i){
			printf("world, current process pid = %d\n", getpid());
			// usleep(100);
		}
	}

	printf("after fork process id : %d \n", getpid());

	pause();
	return 0;
}

