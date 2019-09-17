/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/17 03:26:43 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_lemin(t_lemin *l, t_queue **end, t_room **current, t_room **push)
{
	l->queue = NULL;
	*end = NULL;
	*current = NULL;
	*push = NULL;
	if (!(init_bfs(l, current)))
		return (error_msg(ERR_MALLOC_4));
	return (1);
}

/*
** ==================== init_lemin ====================
** init values declared in lemin function
*/

int		lemin(t_lemin *l)
{
	int		i;
	t_bfs	b;

	i = 1;
	if (!(init_lemin(l, &(b.find_end), &(b.current_room), &(b.room_to_push))))
		return (error_msg(ERR_LEMIN_1));
	b.queue_state = l->queue;
	l->max_paths = nb_max_paths(l);
	while (l->max_paths && bfs(&(b.queue_state), &(b.current_room), &(b.room_to_push)) == 1)
	{
		b.find_end = l->queue;
		while (b.find_end && (b.find_end)->room->end != 1)
			b.find_end = (b.find_end)->next;
		if (!b.find_end)
			return (1);
		put_links_to_full(&(b.find_end));
		if (!update_graph(l))
			return (error_msg(ERR_LEMIN_2));
		free_queue(&(l->queue));
		if (!(init_bfs(l,  &(b.current_room))))
			return (error_msg(ERR_LEMIN_1));
		b.queue_state = l->queue;
		l->max_paths--;
		i++;
	}
	return (1);
}

/*
** ==================== lemin ====================
** init a queue which contain start room at first
** queue_state is a pointer on the actual state of the queue ->
** we use it to avoid parsing all the links we already parse in the previous bfs
** while bfs return another path
** we need to go to end to fill the path in reverse cf doc fill_path ->
** so if we never found an end we start from the begining of the queue ->
** else we start from the previous end ->
** and we go to the next end in either case ->
** the we call fill_path and increment the number of path found
*/
