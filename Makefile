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
FLAGS = -Wall -Wextra -Werror
HEADER = .
SRC = src/main.c
OPTION = -I $(HEADER)
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : libft/libft.a $(OBJ)
	$(CC) $(FLAGS) $(OPTION) -o $(OBJ) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -I $(HEADER) -L libft/ -lft

%.o: %.c libft
	$(CC) $(FLAGS) -c $< $(OPTION)

libft/libft.a :
	make -C libft/

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
