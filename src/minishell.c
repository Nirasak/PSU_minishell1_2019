/*
** EPITECH PROJECT, 2020
** minishell.c
** File description:
** minishell
*/

#include <signal.h>
#include <stdlib.h>
#include "my.h"

int minishell(mysh_t *mysh)
{
    char *input = NULL;
    int status = 0;

    mysh->cmd = NULL;
    while (1) {
        my_printf("$> ");
        signal(SIGINT, SIG_IGN);
        input = get_input();
        mysh->cmd = input_to_command(input);
        if ((status = my_commands(mysh)) == false)
            if ((status = my_exec_binary(mysh)) == false)
                status = my_exec_path(mysh);
    }
    return (0);
}
