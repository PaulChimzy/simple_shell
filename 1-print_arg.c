#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the arguments passed to a program
 * @argc: number of arguments passed to the program including its name
 * @argv: array of arguments passed to the program
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    int count = 1;

    while (argv[count] != NULL)
    {
        printf("%s\n", argv[count]);
        count++;
    }
    return (0);
}