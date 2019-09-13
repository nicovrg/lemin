/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/13 05:48:15 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		count_links(t_room **room)
{
	int		i;
	t_links	*tmp_link;

	i = 0;
	tmp_link = (*room)->links;
	while (tmp_link)
	{
		i++;
		tmp_link = tmp_link->next;
	}
	return (i);
}

/*
** ==================== count_links ====================
** count the number of links of a room
*/

static int		nb_max_paths(t_lemin *l)
{
	int		nb_start_links;
	int		nb_end_links;
	t_room	*tmp;

	nb_end_links = 0;
	nb_start_links = 0;
	tmp = l->room;
	while (tmp && tmp->start != 1)
		tmp = tmp->next;
	nb_start_links = count_links(&tmp);
	tmp = l->room;
	while (tmp && tmp->end != 1)
		tmp = tmp->next;
	nb_end_links = count_links(&tmp);
	if (l->nb_ant <= nb_start_links && l->nb_ant <= nb_end_links)
		return (l->nb_ant);
	if (nb_start_links <= nb_end_links && nb_start_links <= l->nb_ant)
		return (nb_start_links);
	if (nb_end_links <= nb_start_links && nb_end_links <= l->nb_ant)
		return (nb_end_links);
	return (1);	
}

/*
** ==================== nb_max_paths ====================
** return the minimum between nb_ant, nb_start_links, nb_end_links
** this number is the maximum of paths that we search
*/

static int		init_lemin(t_lemin *l, t_queue **find_end, t_room **current_room, t_room **room_to_push)
{
	l->queue = NULL;
	*find_end = NULL;
	*current_room = NULL;
	*room_to_push = NULL;
	if (!(init_bfs(l, current_room)))
		return (error_msg(ERR_MALLOC_4));
	return (1);
}

/*
** ==================== init_lemin ====================
** init values declared in lemin function
*/

int				lemin(t_lemin *l)
{
	int		nb_path;
	t_queue	*find_end;
	t_queue	*queue_state;
	t_room	*room_to_push;
	t_room	*current_room;

	nb_path = 1;
	if (!(init_lemin(l, &find_end, &current_room, &room_to_push)))
		return (0);
	queue_state = l->queue;
	l->max_paths = nb_max_paths(l);
	while (l->max_paths && bfs(&queue_state, &current_room, &room_to_push) == 1)
	{
		find_end = l->queue;
		while (find_end && find_end->room->end != 1)
			find_end = find_end->next;
		if (!find_end)
			return (1);
		put_links_to_full(&find_end);
		free_queue(&(l->queue));
		if (!(init_lemin(l, &find_end, &current_room, &room_to_push)))
			return (0);
		if (!update_graph(l))
			return (0);
		queue_state = l->queue;
		l->max_paths--;
		nb_path++;
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
