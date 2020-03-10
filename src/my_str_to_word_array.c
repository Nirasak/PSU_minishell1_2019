/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** str to word array
*/

#include <stdlib.h>
#include "my.h"

int count_words(char const *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            count++;
    return (count);
}

char **my_str_to_word_array(char const *str, char c)
{
    int count = count_words(str, c);
    int j = 0;
    int x = 0;
    char **array = malloc(sizeof(char *) * (count + 2));

    for (int i = 0; str[i] != '\0'; j++) {
        for (; str[i] == c && str[i] != '\0'; i++);
        if (str[i] == '\0' || array == NULL)
            break;
        for (x = i; str[x] != c && str[x] != '\0'; x++);
        array[j] = malloc(sizeof(char) * (x - i + 2));
        for (x = 0; str[i] != c && str[i] != '\0'; i++) {
            array[j][x] = str[i];
            x++;
        }
        array[j][x] = '\0';
    }
    array[j] = NULL;
    return (array);
}
