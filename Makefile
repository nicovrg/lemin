# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:57:16 by nivergne          #+#    #+#              #
#    Updated: 2019/10/18 19:28:25 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

include mk/include.mk
include mk/src.mk
include mk/obj.mk
include mk/colors.mk

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
CPPFLAGS += -MMD -MP
LIB = libft/libft.a
DEPS = $(subst .o,.d,$(OBJ))

all: $(NAME)

$(NAME): $(OBJ) | makelib
	@echo "$(BOL)$(GRN)LEMIN			$(BLU)compile$(GRN)		[OK]$(END)"
	@$(CC) $(INC_PATH) $(OBJ) -L libft -lft -o $(NAME)

makelib:
	@$(MAKE) -C libft

obj/%.o: src/%.c
	@mkdir -p obj
	@mkdir -p $(dir $@)
	@echo "Building$(BLU) $(patsubst obj/%,%,$(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_PATH) -o $@ -c $<
	@printf "\33[2K"

include mk/bitcoin.mk
include mk/debug.mk
include mk/clean.mk

re: fclean all

.PHONY: all clean fclean re makelib g3 fsanitize bitcoin minotaure bitcoin_autore

-include $(DEPS)
