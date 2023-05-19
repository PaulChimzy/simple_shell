#include <stdio.h>
#include <stdlib.h>
/**
 * main - takes user input and prints to output screen
 * Return: Always 0
 */
int main()
{
    /*size_t val;*/
    size_t bufsize = 2;
    char **Buffer;

    Buffer = malloc(sizeof(char) * (bufsize));
    if (Buffer == NULL)
    {
        printf("Unable to allocate memory for the input\n");
        return (0);
    }
    printf("$ ");
    getline(Buffer, &bufsize, stdin);
    printf("%s\n", *Buffer);

    return (0);
}