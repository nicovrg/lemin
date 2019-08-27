/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/28 00:24:40 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		lemin(t_room **room, t_queue **queue, t_path **paths)
{
	int		nb_path;
	t_queue	*find_end;
	t_queue	*queue_state;
	t_room	*room_to_push;
	t_room	*current_room;

	nb_path = 0;
	find_end = NULL;
	current_room = NULL;
	room_to_push = NULL;
	if (!(init_bfs(room, queue, &current_room)))
		return (error_msg(ERR_MALLOC_4));
	queue_state = (*queue);
	while (bfs(room, &queue_state, &current_room, &room_to_push) == 1)
	{
		find_end = (find_end) ? find_end->next : *queue;
		while (find_end && find_end->room->end != 1)
			find_end = find_end->next;
		if (!(fill_path(nb_path, &find_end, paths)))
			return (error_msg(ERR_MALLOC_9));
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