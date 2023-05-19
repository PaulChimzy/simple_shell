#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - creates a new process and runs all child process
 * Return: Always 0
 */
int main(void)
{
    int status, i;
    pid_t child_pro;
    char *cmd = "./break_down";
    char *argv[] = {"./break_down", "Wow I beilieve I can really do this", NULL};
    char *envp[] = {NULL};

    for (i = 0; i < 5; i++)
    {
        child_pro = fork();
        if (child_pro == 0)
        {
            if (execve(cmd, argv, envp) == -1)
            {
                perror("Error:");
                return (0);
            }
            sleep(3);
        }
        else
        {
            wait(&status);
            printf("finished process %d\n", i);
        }
    }

}