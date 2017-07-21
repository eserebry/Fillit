# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eupopa <eupopa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/09 21:30:08 by eserebry          #+#    #+#              #
#    Updated: 2017/06/04 17:58:39 by eupopa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror -c -I

SRC = ft_main.c\
		ft_fileread.c\
		ft_errors.c\
		ft_square.c\
		ft_check.c\
		ft_makehash.c\
		ft_solution.c\
		ft_array.c\
		ft_to_hash.c\
		ft_tetrinit.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

CC = gcc

LIBFT = ./libft/libft.a
LIBINC = -I./libft
LIBLINK = -L./libft -lft

all: $(NAME)

libft: $(LIBFT)

$(LIBFT):
		make -C ./libft

$(NAME): libft $(OBJ)
		$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

remlib:
	$(RM) $(LIBFT)

remoblib:
	make fclean -C ./libft/

clean: remoblib
		$(RM) $(OBJ)

fclean: clean remoblib
		$(RM) $(NAME)

re: fclean all

.PHONY : all, re, clean, fclean
