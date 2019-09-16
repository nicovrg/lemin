/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 05:03:26 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/13 07:32:38 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define ERR_PARSE_1 "error in check_lines - fail to append room to room list"
# define ERR_PARSE_2 "error in check_lines - empty line"

# define ERR_MALLOC_1 "error in bfs - fail to malloc queue in init_queue"
# define ERR_MALLOC_2 "error in bfs - fail to malloc queue in push_queue"
# define ERR_MALLOC_3 "error in push_queue - fail to strdup prev_name"
# define ERR_MALLOC_4 "error in lemin - fail in init_bfs"
# define ERR_MALLOC_5 "error in fill_path - fail to malloc new_path"
# define ERR_MALLOC_6 "error in fill_path - fail to malloc new_path->lst_rooms"
# define ERR_MALLOC_7 "error in fill_lst_rooms - fail to malloc new_room"
# define ERR_MALLOC_8 "error in fill_lst_rooms - fail to strdup new_room->room"
# define ERR_MALLOC_9 "error in lemin - fill_path return incorrect value"
# define ERR_MALLOC_10 "error in fill_lst_rooms - failed malloc in helper_flr"
# define ERR_MALLOC_11 "error in update_grath - failed malloc new_path in update_grath"
# define ERR_MALLOC_12 "error in update_paths - failed malloc"
# define ERR_MALLOC_13 "error in update_paths - return error from fill_path"
# define ERR_MALLOC_14 "error in fill_path - failed malloc"

# define ERR_LEMIN_1 "error in init_lemin"
# define ERR_LEMIN_2 "error in update_graph"

#endif