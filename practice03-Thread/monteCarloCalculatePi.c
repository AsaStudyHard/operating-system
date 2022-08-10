#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>


void* calculate_pi(void* arg)
{
    // range number 
    unsigned seed = time(NULL);
    
    int circle_points = 0;
    int square_points = 0;
    int intervals = *((int*) arg);
    
    for ( int i = 0; i < intervals * intervals; ++i){
        // get x, y
        double x = (double) rand_r(&seed) / RAND_MAX;  // range (0, 1)
        double y = (double) rand_r(&seed) / RAND_MAX;

        if ((x * x + y * y ) <= 1)
        {
            // mean point is in circle
            circle_points ++;
        }
        
        square_points ++;

    }

    // calculater pi method, this is a fixed equation
    double pi = (double) (4.0 * circle_points) / square_points;
    printf("The estimated PI is %lf in %d times \n", pi, intervals* intervals);

    pthread_exit(0);
}

int main()
{
    clock_t start, delta;
    double user_time;

    start = clock();

    // create 10 thread running func
    pthread_t calculate_pi_thread[10];

    int args[10];

    for (int i = 0; i < 10; ++i){
        args[i] = 1000*(i + 2);
        // create thread, args is parametars
        pthread_create(&calculate_pi_thread[i], NULL, calculate_pi, &args[i]);
    }

    // wait all thread running success
    for(int i = 0; i < 10; ++i){
        pthread_join(calculate_pi_thread[i], NULL);
    }
    delta = clock() - start;

    printf(" The time taken in total : %lf seconds \n", (double) delta / CLOCKS_PER_SEC);

    return 0;
}