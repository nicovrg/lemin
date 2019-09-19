/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 02:08:02 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/18 04:27:24 by qgirard          ###   ########.fr       */
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

t_links		**realloc_tab_links(t_links ***tab, t_links **links)
{
	int		i;
	t_links	**new;

	i = 0;
	new = NULL;
	while (*tab && (*tab)[i])
		i++;
	if (!(new = (t_links **)malloc(sizeof(t_links *) * (i + 2))))
		return (NULL);
	i = 0;
	while (*tab && (*tab)[i])
	{
		new[i] = (*tab)[i];
		i++;
	}
	new[i] = *links;
	new[i + 1] = NULL;
	free(*tab);
	return (new);
}

int		push_queue(t_queue **queue, t_room **room_to_push, t_links **links, t_links ***tab)
{
	t_queue		*new;
	t_queue		*tmp_queue;

	tmp_queue = *queue;
	if (!(*tab = realloc_tab_links(tab, links)))
		return (0);
	while ((*queue) && tmp_queue->next)
		tmp_queue = tmp_queue->next;
	if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
		return (0);
	new->room = *room_to_push;
	new->link = (*links);
	new->prev_link = *queue;
	new->prev = tmp_queue;
	new->next = NULL;
	tmp_queue->next = new;
	return (1);
}

/*
** ==================== push_queue ====================
** add an element at the bottom of the queue
*/
