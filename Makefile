# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 20:27:05 by ksticks           #+#    #+#              #
#    Updated: 2019/09/20 16:48:00 by edrowzee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
FLAGS = #-Wall -Wextra -Werror
SRC = src/main.c \
	src/tetra.c \
	src/draw.c \
	src/plane_iter.c \
	src/solver.c \
	src/tetra_prepare.c \
	src/reader.c
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
	rm -f $(OBJ)
	make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	make -C libft/ fclean

re : fclean all
