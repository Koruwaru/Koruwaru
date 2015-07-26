# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenault <crenault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/09 18:00:27 by crenault          #+#    #+#              #
#    Updated: 2015/05/28 14:58:35 by crenault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# libft
FT_FOLD = common/libft
FT_CHECK = $(FT_FOLD)/.git
FT_LIB = $(FT_FOLD)/libft.a
FT_FLAGS = -L$(FT_FOLD) -lft

# submodules
SUBMODULES = $(FT_CHECK)

# libraries
LIBRARIES = $(FT_LIB)

# sub makefile
FOLDER_ASM = asm
FOLDER_COREWAR = corewar

# all sub makefile
COREWAR_FOLDER = corewar
ASM_FOLDER = asm

# main rule
all: $(COREWAR_FOLDER) $(ASM_FOLDER) $(SUBMODULES) $(LIBRARIES)

# rebuild your bin
re: fclean all

# reclone submodule and rebuild
rere: ffclean all

$(COREWAR_FOLDER):
	@make -C $@
	@echo $@ "updated!"

$(ASM_FOLDER):
	@make -C $@
	@echo $@ "updated!"

# submodules
$(SUBMODULES):
	@git submodule init
	@git submodule update
	@echo $@ "updated!"

# lib libft
$(FT_LIB):
	@make -C $(FT_FOLD)
	@echo $@ "updated!"

# ignore if file, force command name
.PHONY: all re rere clean fclean ffclean cleansubs

# clean o files
clean:
	@make clean -C $(COREWAR_FOLDER)
	@make clean -C $(ASM_FOLDER)

# clean submodules
cleansubs:
	@make clean -C $(FT_FOLD)

# clean exec file and library
fclean: clean
	@make fclean -C $(COREWAR_FOLDER)
	@make fclean -C $(ASM_FOLDER)
	@make fclean -C $(FT_FOLD)

# get empty and clean repo (without libs)
ffclean: fclean cleansubs
