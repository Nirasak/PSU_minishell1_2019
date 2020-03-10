/*
** EPITECH PROJECT, 2020
** get_command.c
** File description:
** get command
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

bool last_char(char *str, int i)
{
    for (; str[i] != '\0'; i++)
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return (false);
    return (true);
}

bool is_new_word(char *str, int j)
{
    int i = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i] != '\0'; i++)
        if ((str[i] == ' ' || str[i] == '\t') && i == j && str[i + 1] != ' '
            && str[i + 1] != '\t' && last_char(str, i) == false)
            return (true);
    return (false);
}

int get_nb_words(char *str)
{
    int count = 1;
    int i = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i] != '\0'; i++)
        if ((str[i] == ' ' || str[i] == '\t')
            && str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0')
            count++;
    return (count);
}

char *get_input(void)
{
    char *str = 0;
    size_t len = 0;

    if (getline(&str, &len, stdin) == -1) {
        my_printf("exit\n");
        exit(0);
    }
    str[len - 1] = '\0';
    return (str);
}

char **input_to_command(char *str)
{
    int nb_words = get_nb_words(str);
    char **tab = malloc(sizeof(char *) * (nb_words + 1));
    int line = 0;
    int c = 0;

    tab[line] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_new_word(str, i) == true) {
            tab[line][c] = '\0';
            line++;
            c = 0;
            tab[line] = malloc(sizeof(char) * (my_strlen(str) + 1));
        } else if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            tab[line][c] = str[i];
            c++;
        }
    }
    tab[line][c] = '\0';
    tab[line + 1] = NULL;
    return (tab);
}
