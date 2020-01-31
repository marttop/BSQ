##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	bsq

SRC	=	main.c \
		utils/get_nb_lines.c \
		utils/get_nb_carac.c \
		utils/file_to_word_array.c \
		utils/get_to_start.c \
		utils/find_my_biggest.c \
		utils/print_final_square.c \
		utils/my_putchar.c \
		utils/error.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra

CFLAGS	+=	-I./include -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
