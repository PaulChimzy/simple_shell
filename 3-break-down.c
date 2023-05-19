#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - breaks down sentences into words based on space delimeter
 * Return - Always 0
 * @argc: number of arguments including name of program
 * @argv: pointer to an array of pointers to the arguments
 */
int main(int argc, char *argv[])
{
    char *sentence;
    char *word;

    if (argv[1] != NULL)
    {
        sentence = argv[1];
    }
    else
    {
        return (0);
    }

    word = strtok(sentence, " ");
    while (word != NULL)
    {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
    return (0);
}