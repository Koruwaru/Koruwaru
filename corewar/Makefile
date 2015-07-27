# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/26 17:12:09 by crenault          #+#    #+#              #
#    Updated: 2015/07/27 15:42:02 by tmielcza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# submodules
SUBMODULES =

# libraries
LIBRARIES =

# compiler
CC = clang
# file type
FT = c
# flags
FLAGS = -Wall -Wextra -Werror
FLAGS += -O3
FLAGS += -g
# binary flags (add libraries)
BIN_FLAGS = $(FLAGS)
# executable
NAME = corewar

# to compile files
#SRC = src/main.c
#SRC += src/genv.c

# header files
HDR = include/vm_types.h
HDR += include/vm_protos.h

# objects files
OBJS = $(SRC:.$(FT)=.o)

# main rule
all: $(NAME)

# rebuild your bin
re: fclean all

# reclone submodule and rebuild
rere: ffclean all

$(NAME): $(SUBMODULES) $(LIBRARIES) $(OBJS)
	@$(CC) -o $@ $(OBJS) $(BIN_FLAGS)
	@echo $@ "updated!"

# making o files
%.o: %.$(FT) $(HDR)
	@$(CC) -o $@ -c $< $(FLAGS)
	@echo $< "updated!"

# submodules
$(SUBMODULES):
	@git submodule init
	@git submodule update
	@echo $@ "updated!"

#
.PHONY: all re rere clean fclean ffclean cleansubs

# clean o files
clean:
	@rm -rf $(OBJS)

# clean submodules
cleansubs:
	@rm -rf $(PI_RESS_LOCAL_DIR)

# clean exec file and library
fclean: clean
	@rm -rf $(NAME)

# get empty and clean repo (without libs)
ffclean: fclean cleansubs
