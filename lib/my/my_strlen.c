/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen
*/

#include <stddef.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (; str[i] != '\0'; i++);
    return (i);
}
