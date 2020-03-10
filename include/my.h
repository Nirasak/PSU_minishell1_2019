/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#define unused __attribute__((unused))

#include <stdbool.h>

typedef struct mysh
{
    char **env;
    char **cmd;
} mysh_t;

int my_printf(char *str, ...);
int my_strlen(char const *str);
int minishell(mysh_t *mysh);
char *get_input(void);
char **input_to_command(char *str);
bool my_commands(mysh_t *mysh);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int len);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_atoi(char *str);
char **cpy_tab(char **tab);
bool my_print_env(mysh_t *mysh);
bool my_unsetenv(mysh_t *mysh);
bool my_setenv(mysh_t *mysh);
void free_tab(char **tab);
int my_exec_binary(mysh_t *mysh);
int my_execve(mysh_t *mysh, char *path);
char *get_from_env(mysh_t *mysh, char *str);
int my_exec_path(mysh_t *mysh);
char **my_str_to_word_array(char const *str, char c);
bool my_cd(mysh_t *mysh);
char *my_strdup(char const *src);
void change_pwd(mysh_t *mysh, int i);

#endif
