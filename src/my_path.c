/*
** EPITECH PROJECT, 2020
** my_path.c
** File description:
** path
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *get_path(char *path, char *cmd)
{
    char *str = malloc(sizeof(char) * (my_strlen(path) + my_strlen(cmd) + 2));
    int len = 0;

    str = my_strcpy(str, path);
    len = my_strlen(str);
    if (str[len - 1] != '/') {
        str[len] = '/';
        str[len + 1] = '\0';
    }
    str = my_strcat(str, cmd);
    return (str);
}

int my_exec_path(mysh_t *mysh)
{
    char *path = get_from_env(mysh, "PATH");
    char **paths = my_str_to_word_array(path, ':');
    char *str = NULL;

    if (access(mysh->cmd[0], X_OK) == 0) {
        my_execve(mysh, mysh->cmd[0]);
        return (1);
    }
    for (int i = 0; paths[i] != NULL; i++) {
        str = get_path(paths[i], mysh->cmd[0]);
        if (access(str, X_OK) == 0) {
            my_execve(mysh, str);
            free(str);
            return (1);
        }
        free(str);
    }
    my_printf("%s: Command not found.\n", mysh->cmd[0]);
    return (1);
}
