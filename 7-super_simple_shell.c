#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - creates a super simple shell
 * Return: Always 0
 */
int main(void)
{
    char **Buffer;
    char *cmd;
    size_t bufsize = 64;
    pid_t child_pro;
    int status;

    char *argv[] = {"./fork_wait", NULL};
    char *envp[] = {NULL};

    Buffer = malloc(sizeof(char) * bufsize);
    if (Buffer == NULL)
    {
        printf("Unable to allocate memory for the input\n");
        return (0);
    }
    printf("$ ");
    getline(Buffer, &bufsize, stdin);
    if (Buffer == NULL)
    {
        printf("Unable to allocate memory\n");
        return (0);
    }
    while (Buffer != NULL)
    {
        child_pro = fork();
        if (child_pro == 0)
        {
            printf("Here: %s", *Buffer);
            cmd = Buffer[0];
            if (execve(cmd, argv, envp) == -1)
            {
                perror("Error:");
                return (0);
            }
        }
        else
        {
            wait(&status);
            printf("$ ");
            getline(Buffer, &bufsize, stdin);
        }
    }
    return (0);

}