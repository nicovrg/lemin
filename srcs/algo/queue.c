/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 02:08:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/26 23:30:17 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			init_queue(t_queue **queue, t_room **room)
{
	t_queue		*new;

	if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	new->room = *room;
	new->prev = NULL;
	new->next = NULL;
	new->prev_room = NULL;
	new->room->discovered = 1;
	if (!(*queue))
		(*queue) = new;
	return (1);
}

/*
** ==================== init_queue ====================
** create and init a queue (list first in first out)
*/

int			push_queue(t_queue **queue, t_room **room, char *prev_name)
{
	t_queue		*new;
	t_queue		*tmp_queue;

	tmp_queue = *queue;
	while ((*queue) && tmp_queue->next)
		tmp_queue = tmp_queue->next;
	if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	new->room = (*room);
	new->room->discovered = 1;
	if (!(new->prev_room = ft_strdup(prev_name)))
		return (error_msg(ERR_MALLOC_3));
	new->prev = tmp_queue;
	new->next = NULL;
	tmp_queue->next = new;
	return (1);
}

/*
** ==================== push_queue ====================
** add an element at the bottom of the queue
*/

t_room*		pop_queue(t_queue **queue)
{
	t_queue *tmp_queue;
		
	tmp_queue = (*queue);
	if ((*queue) && (*queue)->next)
		(*queue) = (*queue)->next;
	else
	{
		(*queue)->room = NULL;
		free(*queue);
		*queue = NULL;
	}
	if (*queue && tmp_queue)
	{
		tmp_queue->room = NULL;
		free(tmp_queue);
		return ((*queue)->room);
	}
	return (NULL);
}

/*
** ==================== pop_queue ====================
** pop an element from the start of the queue
*/

