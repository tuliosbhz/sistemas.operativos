#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include "2.h"

void create_stack()
{
    struct stack_el *stack = (struct stack_el *)malloc(sizeof(struct stack_el));
    stack->str = malloc(sizeof())
}


//Insert a element into the stack
int push(struct stack_el *stack)
{

}
//Retrieve a element into the stack
int pull(struct stack_el *stack)
{

}
//Lists all elements in the stack from top to bottom
int show(struct stack_el *stack)
{

}
int main(int arc, int *argv[])
{
    int n = 10;
    struct stack_el *stack = malloc(n*sizeof(struct stack_el));


}