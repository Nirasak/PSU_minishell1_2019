/*
** EPITECH PROJECT, 2020
** free_tab.c
** File description:
** free tab
*/

#include <stdlib.h>
#include "my.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
