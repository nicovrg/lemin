# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2019/09/22 23:48:39 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_GENERAL =		main.c\
					free_all.c\
					error.c\
					debug.c

SRC_GENERAL := $(addprefix general/, $(SRC_GENERAL))
OBJ_GENERAL := $(addprefix general/, $(addsuffix .o, $(basename $(notdir $(SRC_GENERAL)))))

SRC_PARSE = 		check_lines.c\
					check_map_validity.c\
					check_rooms_and_links.c\
					fill_rooms.c\
					fill_tubes.c

SRC_PARSE := $(addprefix parse/, $(SRC_PARSE))
OBJ_PARSE := $(addprefix parse/, $(addsuffix .o, $(basename $(notdir $(SRC_PARSE)))))

SRC_ALGO = 			bfs.c\
					queue.c\
					lemin.c\
					find_rooms.c\
					test_graph.c\
					count_kchoz.c\
					update_graph.c\
					put_links_to_full.c\
					print_render.c\
					buffer.c\
					move_ants.c

SRC_ALGO := $(addprefix algo/, $(SRC_ALGO))
OBJ_ALGO := $(addprefix algo/, $(addsuffix .o, $(basename $(notdir $(SRC_ALGO)))))

SRC := $(addprefix $(SRC_PATH), $(SRC_GENERAL))
SRC += $(addprefix $(SRC_PATH), $(SRC_PARSE))
SRC += $(addprefix $(SRC_PATH), $(SRC_ALGO))

OBJ := $(addprefix $(OBJ_PATH), $(OBJ_GENERAL))
OBJ += $(addprefix $(OBJ_PATH), $(OBJ_PARSE))
OBJ += $(addprefix $(OBJ_PATH), $(OBJ_ALGO))