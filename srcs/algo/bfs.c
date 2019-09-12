/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/12 01:55:22 by nivergne         ###   ########.fr       */
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

int				bfs(t_queue **queue_state, t_room **current_room, t_room **room_to_push)
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
			// (*room_to_push) = find_room(l, tmp_links->room);
			(*room_to_push) = tmp_links->same_link->coming;
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
