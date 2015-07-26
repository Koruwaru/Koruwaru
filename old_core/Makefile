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

SRC = main.c recup_list.c ft_sp_strsplit.c liste.c begin_pars.c to_print.c \
	  put_unsigned_char_fd.c main2.c to_print2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -o asm $(OBJ) -L libft/ -lft

%.o: %.c
	gcc -Wall -Werror -Wextra -c -I libft/ $<

clean:
	/bin/rm $(OBJ)
	make -C libft/ clean

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
