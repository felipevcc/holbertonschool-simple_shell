#ifndef SHELL_H
#define SHELL_H

/**
 * 
*/
typedef struct command
{
    char *command;
    int (*f)(void);
} command_s;

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*PROTOTYPES*/
int _strcmp(char *s1, char *s2);
int (*check_command(char *cmd))(void);

#endif
