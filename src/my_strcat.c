/*
** EPITECH PROJECT, 2019
** my_strcat.c
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (; dest[i] != '\0'; i++);
    if (src != NULL)
        for (int j = 0; src[j] != '\0'; j++) {
            dest[i] = src[j];
            i++;
        }
    dest[i] = '\0';
    return (dest);
}
