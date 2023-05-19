#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * main - copies a new program into memory of current process
 * Return: Always 0
 */
int main()
{
    /*char *cmd = "./read_line";*/
    int n_chars;
    char *argv[] = {"./break_down", "This is quite an annoying bunch", NULL};
    char *env[] = {NULL};

    char *Buffer = NULL;
    char *buffer_n;
    size_t bufsize = 64;
    /*Buffer = malloc(sizeof(char) * bufsize);*/
    printf("$ ");
    n_chars = getline(&Buffer, &bufsize, stdin);
    buffer_n = malloc(sizeof(char) * n_chars);
    // *Buffer = "./fork_wait";
    strcpy(buffer_n, Buffer);

    if (execve(buffer_n, argv, env) == -1)
    {
        printf("Could not execute execve\n");
    }

    return (0);
}