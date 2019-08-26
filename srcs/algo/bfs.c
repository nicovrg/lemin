/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/27 01:33:29 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_bfs(t_room **room, t_queue **queue, t_room **current_room)
{
	(*current_room) = find_start_room(room);
	if (!init_queue(queue, current_room))
		return (error_msg(ERR_MALLOC_1));
	return (1);
}

/*
** ==================== init_bfs ====================
** init bfs
*/

int		bfs(t_room **room, t_queue **queue, t_room **current_room, t_room **room_to_push)
{
	int		end;
	t_links *tmp_links;

	tmp_links = NULL;
	end = 0;
	while (*queue)
	{
		if (*current_room && (*current_room)->links)
			tmp_links = (*current_room)->links;
		while (tmp_links && (*current_room)->end != 1)
		{
			(*room_to_push) = find_room(room, tmp_links->room);
			if ((*room_to_push)->discovered == 0 && !push_queue(queue, room_to_push, (*current_room)->name))
				return (error_msg(ERR_MALLOC_2));
			if ((*room_to_push)->end == 1)
			{
				(*room_to_push)->discovered = 0;
				end = 1;
			}
			tmp_links = tmp_links->next;
		}
		(*queue) = (*queue)->next;
		if ((*queue))
			(*current_room) = (*queue)->room;
		if (end == 1)
			return (1);
	}
	return (2);
}

/*
** ==================== bfs ====================
** an implementation of breadth first search algorithm
** traverse the graph through breadth
*/
