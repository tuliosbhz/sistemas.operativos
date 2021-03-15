#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc, char const *argv[], char **env)
{
    int fd_in;
    int rc = fork();
    if(rc < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0)
    {
        printf("hello, I am child (pid:%d)\n", (int)getpid());
    } else {
        int rc_wait = wait(NULL);
        printf("hello, I am parent of %d (rc_wait: %d) (pid:%d) \n", rc, rc_wait, (int)getpid());
    }
    fd_in = open(argv[1], O_CREAT, O_RDWR);

    for(int i=1; env[i] != NULL; i++)
    {
    printf("%s\n", env[i]);
    write(fd_in, env[i], sizeof(env[i]));
    }

}