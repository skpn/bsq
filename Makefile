# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edbaudou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/18 19:29:20 by edbaudou          #+#    #+#              #
#    Updated: 2019/02/27 21:04:11 by sikpenou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
NAME = bsq
INCL = ./includes/bsq.h
SRCS = ./srcs/bsq.c ./srcs/parse.c ./srcs/realloc.c ./srcs/main.c \
	   ./srcs/toolbox.c ./srcs/display.c ./srcs/error.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I $(INCL) -o $(NAME)

$(OBJ): $(INCL)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
