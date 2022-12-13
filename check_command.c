#include "shell.h"

/**
 * 
*/
int (*check_command(char *cmd))(void)
{
    int i = 0;

    command_s cmds[] = {
        {"ls", NULL},
        {"exit", NULL},
        {NULL, NULL}
    };

    while(cmds[i].command)
    {
        if (_strcmp(cmd, cmds[i].command) == 0)
            break;
        i++;
    }
    return (cmds[i].f);
}
