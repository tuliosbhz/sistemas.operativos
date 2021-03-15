#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_THREADS 4


int thr_res[NUM_THREADS];

void *thr1_func(void *arg);
void *thr2_func(void *arg);
void *thr3_func(void *arg);
void *thr4_func(void *arg);

typedef struct {
    int op1;
    int op2;
} thr_arg_t;

int main() 
{
    thr_arg_t myarg;
    pthread_t tid[NUM_THREADS];
    myarg.op1 = 10;
    myarg.op2 = 20;
    printf("Insert operands: \n");
    scanf("%d %d", &myarg.op1, &myarg.op2);

    pthread_create(&tid[0],NULL,thr1_func, NULL);
    pthread_create(&tid[1],NULL,thr2_func, NULL);
    pthread_create(&tid[2],NULL,thr3_func, NULL); 
    pthread_create(&tid[3],NULL,thr4_func, NULL);

    //Another option - Dont follow the order
    // for(int i = 0; i < NUM_THREADS; i++)
    // {
    //     pthread_create(&tid[i],NULL,thr1_func, &myarg);
    // }

    for(int i = 0; i < NUM_THREADS; i++)
    {
        //pthread_join(tid[i], NULL); 
        printf("The result of operation is %d\n", thr_res[i]);
    }

}

void *thr1_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    thr_res[0] = args->op1 + args->op2;
    return NULL;
}
void *thr2_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    thr_res[1] = args->op1 - args->op2;
    return NULL;
}
void *thr3_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    thr_res[2] = args->op1 * args->op2;
    return NULL;
}
void *thr4_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    if(args->op2 != 0)
    {
        thr_res[3] = args->op1 / args->op2;
    }else 
    {
        printf("Denominator with zero value in division\n");
        thr_res[3]=-1;
    }
    return NULL;
}