/*
** EPITECH PROJECT, 2020
** my_binary.c
** File description:
** binary
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_exec_binary(mysh_t *mysh)
{
    if (access(mysh->cmd[0], X_OK) == 0 && opendir(mysh->cmd[0]) == NULL
        && mysh->cmd[0][0] == '.' && mysh->cmd[0][1] == '/')
        return (my_execve(mysh, mysh->cmd[0]));
    return (0);
}
