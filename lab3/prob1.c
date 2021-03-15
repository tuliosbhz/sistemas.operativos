#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char const *argv[], char * envp[])
{
    char envar[] = "ENV_VAR";
    char command[64];
    strcpy(command, "ENV_VAR = 20");
    system(command);

    char * env_varname = getenv("ENV_VAR");

    if(env_varname)
        write(STDOUT_FILENO, env_varname, sizeof(env_varname));
    else write(STDOUT_FILENO, "Variable not found", sizeof("Variable not found"));

}