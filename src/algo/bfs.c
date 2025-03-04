/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/10/19 20:07:52 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			init_bfs(t_lemin *l, t_room **current_room)
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

int			set_end(int *end, t_room **room_to_push, t_links **tmp_links)
{
	if ((*tmp_links)->full == 0 && (*room_to_push)->end == 1)
		*end = 1;
	return (1);
}

int			free_tab_links(t_links ***tab, int var)
{
	if (*tab)
		free((*tab));
	return (var);
}

static int	init_values(int *end, t_links ***tab, t_links **tmp_links)
{
	*end = 0;
	*tab = NULL;
	*tmp_links = NULL;
	return (1);
}

int			bfs(t_queue **queue_state, t_room **current_room, t_room **room_to_push)
{
	int			end;
	t_links		**tab;
	t_links		*tmp_links;

	init_values(&end, &tab, &tmp_links);
	while (*queue_state)
	{
		if (*current_room && (*current_room)->links)
			tmp_links = (*current_room)->links;
		while (tmp_links && (*current_room) && (*current_room)->end != 1)
		{
			(*room_to_push) = tmp_links->same_link->coming;
			if (push_room(room_to_push, &tmp_links, queue_state, &tab))
				if (!push_queue(queue_state, room_to_push, &tmp_links, &tab))
					return (free_tab_links(&tab, 0));
			set_end(&end, room_to_push, &tmp_links);
			tmp_links = tmp_links->next;
		}
		*queue_state = (*queue_state)->next;
		if (*queue_state)
			(*current_room) = (*queue_state)->room;
		if (end == 1)
			return (free_tab_links(&tab, 1));
	}
	return (free_tab_links(&tab, 2));
}

/*
** ==================== bfs ====================
** an implementation of breadth first search algorithm
** traverse the graph through breadth and return when end is met
*/
