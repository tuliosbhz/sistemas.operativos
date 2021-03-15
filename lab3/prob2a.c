#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char const *argv[], char **env)
{
    int fd_in;
    fd_in = open(argv[1], O_CREAT, O_RDWR);

    for(int i=1; env[i] != NULL; i++)
    {
    printf("%s\n", env[i]);
    write(fd_in, env[i], sizeof(env[i]));
    }



}