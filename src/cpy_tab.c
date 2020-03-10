/*
** EPITECH PROJECT, 2020
** cpy_tab.c
** File description:
** cpy tab
*/

#include <stdlib.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL)
        exit(84);
    return (my_strcpy(dest, src));
}

char **cpy_tab(char **tab)
{
    int i = 0;
    char **cpy = NULL;

    if (tab == NULL)
        return (NULL);
    for (; tab[i] != NULL; i++);
    cpy = malloc(sizeof(char *) * (i + 10));
    if (cpy == NULL)
        exit(84);
    for (i = 0; tab[i] != NULL; i++)
        cpy[i] = my_strdup(tab[i]);
    cpy[i] = NULL;
    return (cpy);
}
