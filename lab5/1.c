#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

#define DEBUG 0
#define nthreads 3

typedef struct {
    long *cnt;	/* pointer to shared counter */
    int n;		/* no of times to increment */
    int id;		/* application-specific thread-id */
} targ_t;

void *tfun(void *arg) {

    targ_t *targ = (targ_t *) arg;
    int i;
  
    printf("Thread %d starting\n", targ->id);

    printf ("&cnt = %p \n", targ->cnt);

    for(i = 0; i < targ->n ; i++) {
		if( DEBUG ) 
		    printf("b4:  %ld ", *(targ->cnt)); 
	
		(*(targ->cnt))++; 
		/* If cnt is always N*MAX_ITER 
		   Then comment the previous line and 
		   uncomment the following 3 lines 
		   aux = *(targ->cnt);
		   aux++;
		   *(targ->cnt) = aux; 
		   */
		if (DEBUG )
		    printf("\t %ld \n", *(targ->cnt)); 
    }
    printf("Thread %d done\n", targ->id);
    return NULL;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Numero de argumentos errado");
    }

    pthread_t threads[nthreads];
    targ_t arg_count[nthreads];
    arg_count.n = atoi(argv[1]);
    int numthread = 0; 
    for(int i = 0; i < arg_count.n; i++)
    {
        arg_count.id = numthread;
        pthread_create(&threads[i], NULL, tfun, &arg_count);
        printf("Thread %d: Counter %ld\n", arg_count.id, *arg_count.cnt);
        numthread++;
    }

    printf("Final value of the counter is %ld", *arg_count.cnt);

    return 0;

}