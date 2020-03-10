##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/minishell.c	\
		src/get_command.c	\
		src/my_commands.c	\
		src/my_strcmp.c	\
		src/my_atoi.c	\
		src/cpy_tab.c	\
		src/my_strcat.c	\
		src/free_tab.c	\
		src/env.c	\
		src/my_binary.c	\
		src/my_execve.c	\
		src/my_path.c	\
		src/my_str_to_word_array.c	\
		src/my_cd.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	-I include/

LIB	=	-L ./ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:
	make tests_run -C lib/

clean:
	make clean -C lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
