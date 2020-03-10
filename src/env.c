/*
** EPITECH PROJECT, 2020
** env.c
** File description:
** env
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *get_from_env(mysh_t *mysh, char *str)
{
    char *dest = NULL;
    int i = 0;

    for (; mysh->env[i] != NULL; i++)
        if (my_strncmp(mysh->env[i], str, my_strlen(str)) == 0)
            break;
    if (mysh->env[i] == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(mysh->env[i]) + 1));
    if (dest == NULL)
        exit(84);
    dest = my_strcpy(dest, mysh->env[i]);
    for (; *dest != '='; dest++);
    dest++;
    return (dest);
}

char *get_line_env(mysh_t *mysh)
{
    char *line = malloc(sizeof(char) * (my_strlen(mysh->cmd[1])
                                        + my_strlen(mysh->cmd[2]) + 3));

    if (line == NULL)
        exit(84);
    line = my_strcpy(line, mysh->cmd[1]);
    line[my_strlen(mysh->cmd[1])] = '=';
    line[my_strlen(mysh->cmd[1]) + 1] = '\0';
    line = my_strcat(line, mysh->cmd[2]);
    return (line);
}

bool my_print_env(mysh_t *mysh)
{
    for (int i = 0; mysh->env[i] != NULL; i++)
        my_printf("%s\n", mysh->env[i]);
    return (true);
}

bool my_unsetenv(mysh_t *mysh)
{
    bool status = false;

    if (mysh->cmd[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (true);
    }
    for (int i = 0; mysh->env[i] != NULL; i++) {
        if (my_strncmp(mysh->env[i], mysh->cmd[1],
                        my_strlen(mysh->cmd[1]) - 1) == 0
            && mysh->env[i][my_strlen(mysh->cmd[1])] == '=') {
            free(mysh->env[i]);
            status = true;
        }
        if (status == true)
            mysh->env[i] = mysh->env[i + 1];
    }
    return (true);
}

bool my_setenv(mysh_t *mysh)
{
    int i = 0;
    char **tmp = NULL;
    char *line = get_line_env(mysh);

    for (; mysh->env[i] != NULL; i++)
        if (my_strncmp(mysh->env[i], mysh->cmd[1],
                        my_strlen(mysh->cmd[1]) - 1) == 0
            && mysh->env[i][my_strlen(mysh->cmd[1])] == '=') {
            free(mysh->env[i]);
            mysh->env[i] = line;
            return (true);
        }
    tmp = cpy_tab(mysh->env);
    free_tab(mysh->env);
    tmp[i] = line;
    tmp[i + 1] = NULL;
    mysh->env = tmp;
    return (true);
}
