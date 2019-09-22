# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    src.mk                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 23:46:29 by nivergne          #+#    #+#              #
#    Updated: 2019/09/23 00:03:14 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH := src/

SRC_GENERAL =		main.c\
					free_all.c\
					error.c\
					debug.c

SRC_GENERAL := $(addprefix general/, $(SRC_GENERAL))

SRC_PARSE = 		check_lines.c\
					check_map_validity.c\
					check_rooms_and_links.c\
					fill_rooms.c\
					fill_tubes.c

SRC_PARSE := $(addprefix parse/, $(SRC_PARSE))

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

SRC := $(addprefix $(SRC_PATH), $(SRC_GENERAL))
SRC += $(addprefix $(SRC_PATH), $(SRC_PARSE))
SRC += $(addprefix $(SRC_PATH), $(SRC_ALGO))
