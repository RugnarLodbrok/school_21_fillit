# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:27:05 by ksticks           #+#    #+#              #
#    Updated: 2019/09/09 19:37:20 by ksticks          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
FLAGS = #-Wall -Wextra -Werror
SRC = src/main.c \
	src/solver.c
OPTION = -I. -Iheaders
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : libft/libft.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(OPTION) -L libft/ -lft

%.o: %.c libft/libft.a
	@echo compile $(<) "->" $(<:.c=.o)
	@$(CC) $(FLAGS) -c $(<) -o $(<:.c=.o) $(OPTION)

libft/libft.a :
	make -C libft/

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
