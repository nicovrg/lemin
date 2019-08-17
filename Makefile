# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 01:57:16 by nivergne          #+#    #+#              #
#    Updated: 2019/08/17 14:42:00 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

INC_PATH := include/
SRC_PATH := srcs/
OBJ_PATH := obj/

INC_LEMIN =		lemin.h

INC_LEMIN := $(addprefix include/, $(INC_LEMIN))

SRC_GENERAL =		main.c\
					free_all.c\
					error.c

SRC_GENERAL := $(addprefix general/, $(SRC_GENERAL))
OBJ_GENERAL := $(addprefix general/, $(addsuffix .o, $(basename $(notdir $(SRC_GENERAL)))))

SRC_PARSE = 		check_lines.c\
					check_map_validity.c\
					check_rooms_and_links.c\
					fill_rooms.c\
					fill_tubes.c\
					fill_paths.c\
					check_paths.c\
					rooms_visited.c

SRC_PARSE := $(addprefix parse/, $(SRC_PARSE))
OBJ_PARSE := $(addprefix parse/, $(addsuffix .o, $(basename $(notdir $(SRC_PARSE)))))

SRC_ALGO = 			

SRC_ALGO := $(addprefix algo/, $(SRC_ALGO))
OBJ_ALGO := $(addprefix algo/, $(addsuffix .o, $(basename $(notdir $(SRC_ALGO)))))

SRC := $(addprefix $(SRC_PATH), $(SRC_GENERAL))
SRC += $(addprefix $(SRC_PATH), $(SRC_PARSE))
SRC += $(addprefix $(SRC_PATH), $(SRC_ALGO))

OBJ := $(addprefix $(OBJ_PATH), $(OBJ_GENERAL))
OBJ += $(addprefix $(OBJ_PATH), $(OBJ_PARSE))
OBJ += $(addprefix $(OBJ_PATH), $(OBJ_ALGO))


INC = -I./include
INC_PATH = -Iinclude/ -Ilibft/include

GCC_FLAG = -Wall -Wextra -Werror -g
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

obj/%.o: srcs/%.c $(INC_LEMIN)
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
	@mkdir -p obj/general
	@mkdir -p obj/parse
	@mkdir -p obj/algo

clean_lib:
	@make -C libft clean

clean: clean_lib
	@/bin/rm -fr obj

fclean: clean
	@make -C libft fclean
	@echo "$(CYA)$(BOL)LEMIN			$(BLU)bin$(END)$(RED)		[delete]$(END)"
	@/bin/rm -f $(NAME)

re: fclean all

bitcoin:
	@echo "$(DARK_PURPLE)______ _   ___   __    ______ _____ _____ _____ _____ _____ _   _"
	@echo "$(DARK_PURPLE)| ___ \ | | \ \ / /    | ___ \_   _|_   _/  __ \  _  |_   _| \ | |"
	@echo "$(DARK_PINK)| |_/ / | | |\ V /     | |_/ / | |   | | | /  \/ | | | | | |  \| |"
	@echo "$(PURPLE)| ___ \ | | | \ /      | ___ \ | |   | | | |   | | | | | | |     |"
	@echo "$(PINK)| |_/ / |_| | | |      | |_/ /_| |_  | | | \__/\ \_/ /_| |_| |\  |"
	@echo "$(PINK)\____/ \___/  \_/      \____/ \___/  \_/  \____/\___/ \___/\_| \_/"
	@echo "$(END)"

minotaure:
	@echo "$(PURPLE)                                                                 _"
	@echo "$(PURPLE)                                                               _( (~\\"
	@echo "$(PURPLE)        _ _                        /                          ( \> > \\"
	@echo "$(PURPLE)    -/~/ / ~\                     :;                \       _  > /(~\\/"
	@echo "$(PURPLE)   || | | /\ ;\                   |l      _____     |;     ( \/ /  \\ /"
	@echo "$(PURPLE)   _\\)\)\)/ ;;;                   '8o __/-~     ~\   d|     \       /"
	@echo "$(PURPLE)  ///(())(__/~;;\                  \"88p;.  -._ \_;.oP        (_._/_/"
	@echo "$(PURPLE) (((__   __ \\   \                   '>,% (\  (\./)8\"         ;:'  i"
	@echo "$(PURPLE) )))--'.'-- (( ;,8 \               ,;%%%:  ./V^^^V'          ;.   ;."
	@echo "$(PURPLE) ((\   |   /)) .,88  ': ..,,;;;;,-::::::'_::\   ||\          ;[8:  ;"
	@echo "$(PURPLE)  )|  ~-~  |(|(888; ..``'::::8888oooooo.     :\'^^^/,,~--._    |88::||"
	@echo "$(PURPLE)   \ -===- /|  \8;; '':.      oo.8888888888:'((( o.ooo8888Oo;:;:'  |"
	@echo "$(PURPLE)  |_~-___-~_|   '-\.   '        'o'88888888b' )) 888b88888P""'     ;/"
	@echo "$(PURPLE)   ;~~~~;~~         \"'--_'.       b'888888888;(.,"888b888"  ..::;-'"
	@echo "$(PURPLE)    ;      ;              ~\"-....  b'8888888:::::.'8888. .:;;;''"
	@echo "$(PURPLE)       ;    ;                 ':::. ':::OOO:::::::.'OO' ;;;''"
	@echo "$(PURPLE)  :       ;                     '.      \"''::::::''    .'"
	@echo "$(PURPLE)     ;                           '.   \_              /"
	@echo "$(PURPLE)   ;       ;                       +:   ~~--  ':'  -';"
	@echo "$(PURPLE)                                    ':         : .::/"
	@echo "$(PURPLE)       ;                            ;;+_  :::. :..;;;"

bitcoin_autore:
	@echo "$(PURPLE)                                                                 _"
	@echo "$(PURPLE)                                                               _( (~\\"
	@echo "$(PURPLE)        _ _                        /                          ( \> > \\"
	@echo "$(PURPLE)    -/~/ / ~\                     :;                \       _  > /(~\\/"
	@echo "$(PURPLE)   || | | /\ ;\                   |l      _____     |;     ( \/ /  \\ /"
	@echo "$(PURPLE)   _\\)\)\)/ ;;;                   '8o __/-~     ~\   d|     \       /"
	@echo "$(PURPLE)  ///(())(__/~;;\                  \"88p;.  -._ \_;.oP        (_._/_/"
	@echo "$(PURPLE) (((__   __ \\   \                   '>,% (\  (\./)8\"         ;:'  i"
	@echo "$(PURPLE) )))--'.'-- (( ;,8 \               ,;%%%:  ./V^^^V'          ;.   ;."
	@echo "$(PURPLE) ((\   |   /)) .,88  ': ..,,;;;;,-::::::'_::\   ||\          ;[8:  ;          $(DARK_PURPLE)______ _   ___   __    ______ _____ _____ _____ _____ _____ _   _"
	@echo "$(PURPLE)  )|  ~-~  |(|(888; ..``'::::8888oooooo.     :\'^^^/,,~--._    |88::||          $(DARK_PURPLE)| ___ \ | | \ \ / /    | ___ \_   _|_   _/  __ \  _  |_   _| \ | |"
	@echo "$(PURPLE)   \ -===- /|  \8;; '':.      oo.8888888888:'((( o.ooo8888Oo;:;:'  |          $(DARK_PINK)| |_/ / | | |\ V /     | |_/ / | |   | | | /  \/ | | | | | |  \| |"
	@echo "$(PURPLE)  |_~-___-~_|   '-\.   '        'o'88888888b' )) 888b88888P""'     ;/           $(PURPLE)| ___ \ | | | \ /      | ___ \ | |   | | | |   | | | | | | |     |"
	@echo "$(PURPLE)   ;~~~~;~~         \"'--_'.       b'888888888;(.,"888b888"  ..::;-'             $(PINK)| |_/ / |_| | | |      | |_/ /_| |_  | | | \__/\ \_/ /_| |_| |\  |"
	@echo "$(PURPLE)    ;      ;              ~\"-....  b'8888888:::::.'8888. .:;;;''              $(PINK)\____/ \___/  \_/      \____/ \___/  \_/  \____/\___/ \___/\_| \_/"
	@echo "$(PURPLE)       ;    ;                 ':::. ':::OOO:::::::.'OO' ;;;''"
	@echo "$(PURPLE)  :       ;                     '.      \"''::::::''    .'"
	@echo "$(PURPLE)     ;                           '.   \_              /"
	@echo "$(PURPLE)   ;       ;                       +:   ~~--  ':'  -';"
	@echo "$(PURPLE)                                    ':         : .::/"
	@echo "$(PURPLE)       ;                            ;;+_  :::. :..;;;"

debug_makefile:
	@echo "$(SRC)"
	@echo "$(OBJ)"

.PHONY: all clean fclean re libft_clean proj_clean


#INC = $(shell find include -type f | grep -e \.h$$)
#SRC = $(shell find src -type f | grep -e \.c$$)
#patsubst: remplace le deuxieme arg par le troisieme
#basename: remplace le nom en .c par le non sans le .c
