//Copy from a file to another
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 128

int buff[BUFF_SIZE];

//Read the name of the file and print the content after
int main(int argc, char *argv[])
{
    int fd_in, fd_out;
    ssize_t endof;
    printf("%d", argc);
    if(argc > 3)
    {
        write(STDOUT_FILENO, "Error in the argc parameter", sizeof("Error in the argc parameter"));
        exit(1);
    }
    fd_in = open(argv[1], O_NONBLOCK, O_RDONLY);
    fd_out = open(argv[2], O_CREAT);

    while(1)
    {
        endof = read(fd_in, buff, BUFF_SIZE);
        if(endof == 0)
        {
            write(fd_out, buff, BUFF_SIZE);
            exit(0);
        }
        write(fd_out, buff, BUFF_SIZE);
    }

    return 0;
}