/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/11 20:24:05 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				init_bfs(t_lemin *l, t_room **current_room)
{
	(*current_room) = find_start_room(l);
	if (!init_queue(l, current_room))
		return (error_msg(ERR_MALLOC_1));
	return (1);
}

/*
** ==================== init_bfs ====================
** init bfs
*/

int				bfs(t_lemin *l, t_queue **queue_state, t_room **current_room, t_room **room_to_push)
{
	int			end;
	t_links		*tmp_links;

	end = 0;
	tmp_links = NULL;
	while (*queue_state)
	{
		if (*current_room && (*current_room)->links)
			tmp_links = (*current_room)->links;
		while (tmp_links && (*current_room) && (*current_room)->end != 1)
		{
			// (*room_to_push) = tmp_links->ptr_room;
			(*room_to_push) = find_room(l, tmp_links->room);
			if ((*room_to_push)->start != 1 && tmp_links->full == 0
			&& (!(*queue_state)->prev_link
			|| ft_strcmp(tmp_links->room, (*queue_state)->prev_link->room->name)))
				if (!push_queue(queue_state, room_to_push, &tmp_links))
					return (error_msg(ERR_MALLOC_2));
			if (tmp_links->full == 0 && (*room_to_push)->end == 1)
				end = 1;
			tmp_links = tmp_links->next;
		}
		*queue_state = (*queue_state)->next;
		if (*queue_state)
			(*current_room) = (*queue_state)->room;
		if (end == 1)
			return (1);
	}
	return (2);
}

/*
** ==================== bfs ====================
** an implementation of breadth first search algorithm
** traverse the graph through breadth and return when end is met
*/

// int		link_is_passed(char *prev_link, char *current_room, char *room_to_push)
// {
// 	if (!ft_strcmp(current_room, ft_strchr(prev_link, '-') + 1)
// 	&& !ft_strncmp(room_to_push, prev_link, ft_strchr(prev_link, '-') - prev_link))
// 		return (0);
// 	return (1);
// }

// int		bfs(t_room **room, t_queue **queue, t_room **current_room, t_room **room_to_push)
// {
// 	int		end;
// 	t_links *tmp_links;

// 	tmp_links = NULL;
// 	end = 0;
// 	while (*queue)
// 	{
// 		if (*current_room && (*current_room)->links)
// 			tmp_links = (*current_room)->links;
// 		while (tmp_links && (*current_room) && (*current_room)->end != 1)
// 		{
// 			(*room_to_push) = find_room(room, tmp_links->room);
// 			if (tmp_links->full == 0 && (!(*queue)->prev_link
// 			|| ft_strcmp(tmp_links->room, (*queue)->prev_link->room->name)))
// 				if (!push_queue(queue, room_to_push, (*current_room)->name))
// 					return (error_msg(ERR_MALLOC_2));
// 			tmp_links->full = 1;
// 			if ((*room_to_push)->end == 1)
// 			{
// 				tmp_links->full = 0;
// 				end = 1;
// 			}
// 			tmp_links = tmp_links->next;
// 		}
// 		(*queue) = (*queue)->next;
// 		if ((*queue))
// 			(*current_room) = (*queue)->room;
// 		if (end == 1)
// 			return (1);
// 	}
// 	return (2);
// }
