#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int global1, global2, glob_result;

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
    pthread_t tid1, tid2, tid3, tid4;
    myarg.op1 = 10;
    myarg.op2 = 20;
    // pthread_create(&tid1,NULL,thr1_func, NULL);
    // pthread_join(tid1, NULL); 
    // pthread_create(&tid2,NULL,thr2_func, NULL);
    // pthread_join(tid1, NULL); 
    // pthread_create(&tid3,NULL,thr3_func, NULL);
    // pthread_join(tid1, NULL); 
    // pthread_create(&tid4,NULL,thr4_func, NULL);
    // pthread_join(tid1, NULL); 

    //Another option - Dont follow the order

    pthread_create(&tid1,NULL,thr1_func, &myarg);
    pthread_create(&tid2,NULL,thr2_func, &myarg);
    pthread_create(&tid3,NULL,thr3_func, &myarg);
    pthread_create(&tid4,NULL,thr4_func, &myarg);

    pthread_join(tid1, NULL); 
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL); 
    pthread_join(tid4, NULL);  

}

void *thr1_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    glob_result = args->op1 + args->op2;
    printf("The sum of %d + %d = %d\n", args->op1, args->op2, glob_result);
    return NULL;
}
void *thr2_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    glob_result = args->op1 - args->op2;
    printf("The subtraction of %d - %d = %d\n", args->op1, args->op2, glob_result);
    return NULL;
}
void *thr3_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    glob_result = args->op1 * args->op2;
    printf("The multiplication of %d * %d = %d\n", args->op1, args->op2, glob_result);
    return NULL;
}
void *thr4_func(void *arg)
{
    thr_arg_t *args = (thr_arg_t *) arg;
    if(args->op2 != 0)
    {
        glob_result = args->op1 / args->op2;
        printf("The division of %d + %d = %d\n", args->op1, args->op2, glob_result);

    }else 
    {
        printf("Denominator with zero value in division\n");
        glob_result=-1;
    }
    return NULL;
}