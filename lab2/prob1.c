//Cat function
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 128

int buff[BUFF_SIZE];

//Read the name of the file and print the content after
int main(int argc, char *argv[])
{
    int fd_in;
    ssize_t endof;
    if(argc > 2)
    {
        write(STDOUT_FILENO, "Error in the argc parameter", sizeof("Error in the argc parameter"));
        exit(1);
    }
    fd_in = open(argv[1], O_NONBLOCK, O_RDONLY);
    while(1)
    {
        endof = read(fd_in, buff, BUFF_SIZE);
        if(endof == 0)
        {
            write(STDOUT_FILENO, buff, BUFF_SIZE);
            exit(0);
        }
        write(STDOUT_FILENO, buff, BUFF_SIZE);
    }

    return 0;
}