/*
** EPITECH PROJECT, 2020
** my_execve.c
** File description:
** execve
*/

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my.h"

int my_waitpid(pid_t pid)
{
    int status = 0;

    waitpid(pid, &status, 0);
    if (WIFEXITED(status) == 0) {
        my_printf("%s", strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status) == 128)
            my_printf(" (core dumped)");
        my_printf("\n");
    }
    return (0);
}

int my_execve(mysh_t *mysh, char *path)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        my_printf("error with fork\n");
    } else if (pid == 0) {
        if (execve(path, mysh->cmd, mysh->env) == -1)
            exit(0);
    } else
        my_waitpid(pid);
    return (1);
}
