//size of variables
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int a[10];
struct complex {
    double re, im;
} z;
char *hello = "Hello, World!";

int main(int argc, char *argv[])
{
    if(argc > 2)
    {
        write(STDOUT_FILENO, "Error in the argc parameter", sizeof("Error in the argc parameter"));
        exit(1);
    }
    printf("QUESTION A \n");
    size_t lgth;
    printf("Size of a char: %ld \n", sizeof(char));
    printf("Size of a short: %ld \n", sizeof(short));
    printf("Size of a int: %ld \n", sizeof(int));
    printf("Size of a long: %ld \n", sizeof(long));
    printf("Size of a long long: %ld \n\n", sizeof(long long));

    printf("QUESTION B \n");
    printf("Size of the struct complex: %ld \n", sizeof(z));
    printf("Size of the string hello: %ld \n\n", sizeof(hello));

    printf("QUESTION C \n");
    printf("Size of the struct complex: %ld \n", sizeof(a[0]));
    printf("Size of the string hello: %ld \n", sizeof(*hello));
    
    return 0;

}

