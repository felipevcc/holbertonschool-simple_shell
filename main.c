#include "shell.h"

/**
 * main -
*/
int main(void)
{
    int (*func)(void);
    char command[256];

    while (1)
    {
        printf("$ ");
        scanf(" %99[^\n]", command);
        func = check_command(command);

        if (!func)
            break;
        
        printf("\n");
    }
    return (0);
}