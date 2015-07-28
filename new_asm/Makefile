# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/02 23:05:59 by jyim              #+#    #+#              #
#    Updated: 2014/02/02 23:28:21 by jyim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = main.c get_next_line.c op.c ft_sp_strsplit.c utils.c list.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o asm $(OBJ) -L ../common/libft/ -lft

%.o: %.c
	gcc -Wall -Werror -Wextra -c -I libft/ $<

clean:
	/bin/rm $(OBJ)

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)

re: fclean all
