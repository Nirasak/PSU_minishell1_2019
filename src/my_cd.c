/*
** EPITECH PROJECT, 2020
** my_cd.c
** File description:
** cd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void change_pwd(mysh_t *mysh, int i)
{
    char *str = malloc(sizeof(char) * 1024);

    if (str == NULL)
        exit(84);
    if (getcwd(str, 1024) == NULL)
        return;
    if (mysh->env[i] != NULL)
        free(mysh->env[i]);
    else
        mysh->env[i + 1] = NULL;
    mysh->env[i] = malloc(sizeof(char) * (my_strlen(str) + 5));
    if (mysh->env[i] == NULL)
        exit(84);
    mysh->env[i] = my_strcpy(mysh->env[i], "PWD=");
    mysh->env[i] = my_strcat(mysh->env[i], str);
    free(str);
    return;
}

void change_oldpwd(mysh_t *mysh, int i, int j)
{
    for (; mysh->env[i] != NULL; i++)
        if (my_strncmp(mysh->env[i], "PWD", 3) == 0)
            break;
    for (; mysh->env[j] != NULL; j++)
        if (my_strncmp(mysh->env[j], "OLDPWD", 6) == 0)
            break;
    if (mysh->env[i] == NULL) {
        change_pwd(mysh, i);
        return;
    }
    if (mysh->env[j] != NULL)
        free(mysh->env[j]);
    else
        mysh->env[j + 1] = NULL;
    mysh->env[j] = malloc(sizeof(char) * (my_strlen(mysh->env[i]) + 4));
    if (mysh->env[j] == NULL)
        exit(84);
    mysh->env[j] = my_strcpy(mysh->env[j], "OLD");
    mysh->env[j] = my_strcat(mysh->env[j], mysh->env[i]);
    change_pwd(mysh, i);
}

bool my_cd(mysh_t *mysh)
{
    struct stat st;

    if (mysh->cmd[2] != NULL) {
        write(2, "cd: Too many arguments.\n", 24);
        return (true);
    }
    if (mysh->cmd[1] == NULL || my_strcmp(mysh->cmd[1], "~") == 0) {
        chdir(get_from_env(mysh, "HOME"));
    } else if (my_strcmp(mysh->cmd[1], "-") == 0) {
        if (chdir(get_from_env(mysh, "OLDPWD")) == -1)
            write(2, ": No such file or directory.\n", 29);
    } else if (chdir(mysh->cmd[1]) == -1) {
        write(2, mysh->cmd[1], my_strlen(mysh->cmd[1]));
        if (lstat(mysh->cmd[1], &st) != -1 && (st.st_mode & S_IFMT) != S_IFDIR)
            write(2, ": Not a directory.\n", 19);
        else
            write(2, ": No such file or directory.\n", 29);
    }
    change_oldpwd(mysh, 0, 0);
    return (true);
}
