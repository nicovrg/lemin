/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 02:08:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/13 08:30:00 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	init_queue(t_lemin *l, t_room **current_room)
{
	t_queue		*new;

	if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	new->room = *current_room;
	new->prev = NULL;
	new->link = NULL;
	new->next = NULL;
	new->prev_link = NULL;
	if (!l->queue)
		l->queue = new;
	return (1);
}

/*
** ==================== init_queue ====================
** create and init a queue (list first in first out)
*/

int	push_queue(t_queue **queue_state, t_room **room_to_push, t_links **tmp_links)
{
	t_queue		*new;
	t_queue		*tmp_queue;

	tmp_queue = *queue_state;
	while (*queue_state && tmp_queue->next)
		tmp_queue = tmp_queue->next;
	if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	new->room = *room_to_push;
	new->link = (*tmp_links);
	new->prev_link = *queue_state;
	new->prev = tmp_queue;
	new->next = NULL;
	tmp_queue->next = new;
	return (1);
}

/*
** ==================== push_queue ====================
** add an element at the bottom of the queue
*/
