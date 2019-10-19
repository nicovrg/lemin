# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:57:16 by nivergne          #+#    #+#              #
#    Updated: 2019/10/20 01:06:40 by nicolasv         ###   ########.fr        #
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
	@echo "$(BOLD)$(GREEN)LEMIN			$(BLUE)compile$(GREEN)		[OK]$(END)"
	@$(CC) $(INC_PATH) $(OBJ) -L libft -lft -o $(NAME)

makelib:
	@$(MAKE) -C libft

obj/%.o: src/%.c
	@mkdir -p obj
	@mkdir -p $(dir $@)
	@echo "$(BOLD)$(CYAN)lemin		$(BLUE)$(patsubst obj/%, %, $(basename $@))	$(GREEN)[OK]$(END)"
	@printf "$(UP_LINE)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INC_PATH) -o $@ -c $<
	@printf "$(ERASE_LINE)"

include mk/bitcoin.mk
include mk/debug.mk
include mk/clean.mk

re: fclean all

.PHONY: all clean fclean re makelib g3 fsanitize bitcoin minotaure bitcoin_autore

-include $(DEPS)
