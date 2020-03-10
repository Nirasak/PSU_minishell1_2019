/*
** EPITECH PROJECT, 2020
** my_commands.c
** File description:
** commands
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void my_exit(mysh_t *mysh)
{
    my_printf("exit\n");
    if (mysh->cmd[1] == NULL)
        exit(0);
    exit(my_atoi(mysh->cmd[1]));
}

bool hub_setenv(mysh_t *mysh)
{
    if (mysh->cmd[1] == NULL)
        return (my_print_env(mysh));
    if (mysh->cmd[2] != NULL && mysh->cmd[3] != NULL) {
        write(2, "setenv: Too many arguments.\n", 28);
        return (true);
    }
    return (my_setenv(mysh));
}

bool my_commands(mysh_t *mysh)
{
    if (my_strcmp(mysh->cmd[0], "exit") == 0)
        my_exit(mysh);
    if (my_strcmp(mysh->cmd[0], "env") == 0)
        return (my_print_env(mysh));
    if (my_strcmp(mysh->cmd[0], "unsetenv") == 0)
        return (my_unsetenv(mysh));
    if (my_strcmp(mysh->cmd[0], "setenv") == 0)
        return (hub_setenv(mysh));
    if (my_strcmp(mysh->cmd[0], "cd") == 0)
        return (my_cd(mysh));
    return (false);
}
