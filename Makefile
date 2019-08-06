# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:57:16 by nivergne          #+#    #+#              #
#    Updated: 2019/08/06 03:54:36 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

INC = -I./include
INC_PATH = -Iinclude/ -Ilibft/include

INC_LEMIN =		lemin.h

INC_LEMIN := $(addprefix include/, $(INC_LEMIN))

SRC_LEMIN =			main.c\
					checklines.c\
					fill_lists.c\
					check_map_validity.c\
					free_lists.c\
					error.c\
					check_rooms_and_links.c\

SRC = $(addprefix $(SRC_PATH)/, $(SRC_LEMIN))
OBJ = $(SRC:src/%.c=obj/%.o)

SRC_PATH = srcs/
GCC_FLAG = -Wall -Wextra -Werror
# -g3 -fsanitize=address
CC = gcc $(GCC_FLAG) $(INC_PATH)
LIB = libft/libft.a

GRN =		\x1b[32m
YEL =		\x1b[33m
BLU =		\x1b[34m
RED =		\x1b[31m
PUR =		\x1b[35m
CYA =		\x1b[36m
GRY =		\x1b[40m
UND =		\x1b[4m
REV =		\x1b[7m
BOL =		\x1b[1m
END =		\x1b[0m

DARK_PURPLE		=			\033[38;2;65;0;255m
DARK_PINK		= 			\033[38;2;86;0;255m
PURPLE			=			\033[38;2;114;0;255m
PINK			=			\033[38;2;152;0;255m

all: $(NAME)

$(NAME): makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)LEMIN			$(BLU)compile$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)

makelib:
	@$(MAKE) -C libft

obj/%.o: src/%.c $(INC_LEMIN)
	@echo "Building$(BLU) $(patsubst obj/%,%,$(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf "\33[2K"

debug: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)LEMIN			$(BLU)debug$(GRN)		[OK]$(END)"
	@$(CC) $(CFLAGS) -g3 $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)_debug

fsanitize: makelib obj $(LIB) $(OBJ)
	@echo "$(BOL)$(GRN)LEMIN			$(BLU)fsanitize$(GRN)	[OK]$(END)"
	@$(CC) $(CFLAGS) -g3 -fsanitize=address $(INC_PATH) $(OBJ) $(MLX) -L libft -lft -o $(NAME)_fsanitize

obj:
	@mkdir -p obj

clean_lib:
	@make -C libft clean

clean: clean_lib
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(CYA)$(BOL)LEMIN			$(BLU)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(NAME)

re: fclean all

easter_egg:
	@echo "$(DARK_PURPLE)______ _   ___   __ ______ _____ _____ _____ _____ _____ _   _"
	@echo "$(DARK_PURPLE)| ___ \ | | \ \ / / | ___ \_   _|_   _/  __ \  _  |_   _| \ | |"
	@echo "$(DARK_PINK)| |_/ / | | |\ V /  | |_/ / | |   | | | /  \/ | | | | | |  \| |"
	@echo "$(PURPLE)| ___ \ | | | \ /   | ___ \ | |   | | | |   | | | | | | |     |"
	@echo "$(PINK)| |_/ / |_| | | |   | |_/ /_| |_  | | | \__/\ \_/ /_| |_| |\  |"
	@echo "$(PINK)\____/ \___/  \_/   \____/ \___/  \_/  \____/\___/ \___/\_| \_/"
	@echo "$(END)"

.PHONY: all clean fclean re libft_clean proj_clean


#INC = $(shell find include -type f | grep -e \.h$$)
#SRC = $(shell find src -type f | grep -e \.c$$)
#patsubst: remplace le deuxieme arg par le troisieme
#basename: remplace le nom en .c par le non sans le .c
