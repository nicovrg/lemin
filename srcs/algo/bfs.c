/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/18 04:37:53 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	init_bfs(t_lemin *l, t_room **current_room)
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

int	push_room(t_room **room_to_push, t_links **tmp_links, t_queue **queue_state, t_links ***tab)
{
	int		i;

	i = 0;
	while ((*tab) && (*tab)[i])
	{
		if ((*tab)[i] == *tmp_links)
			return (0);
		i++;
	}
	if ((*room_to_push)->start != 1 && (*tmp_links)->full == 0)
	{
		if (!(*queue_state)->prev_link)
			return (1);
		if (ft_strcmp((*tmp_links)->room, (*queue_state)->prev_link->room->name))
			return (1);
	}
	return (0);
}

/*
** ==================== push_room ====================
** check if the room meet condition to be added to the queue
*/

int	set_end(int *end, t_room **room_to_push, t_links **tmp_links)
{
	if ((*tmp_links)->full == 0 && (*room_to_push)->end == 1)
		*end = 1;
	return (1);
}

int	free_tab_links(t_links ***tab, int var)
{
	if (*tab)
		free((*tab));
	return (var);
}

int	bfs(t_queue **queue_state, t_room **current_room, t_room **room_to_push)
{
	int			end;
	t_links		**tab;
	t_links		*tmp_links;

	end = 0;
	tab = NULL;
	tmp_links = NULL;
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
