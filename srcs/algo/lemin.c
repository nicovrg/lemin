/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/27 01:17:29 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ==================== pseudocode ====================
** while (bfs == true)
** update grap
** check graph output
** id new result is better, memorise result

** print result
*/

int		fill_lst_rooms(t_queue **find_end, t_links **lst_rooms)
{
	t_queue		*ptr_end;
	t_links		*new_room;
	t_links		*tmp_link;

	while ((*find_end)->room->start != 1)
	{
		ptr_end = (*find_end);
		tmp_link = (*lst_rooms);
		while (*lst_rooms && tmp_link->next)
			tmp_link = tmp_link->next;
		if (!(new_room = (t_links *)ft_memalloc(sizeof(t_links))))
			return (error_msg(ERR_MALLOC_7));
		if (!(new_room->room = ft_strdup((*find_end)->room->name)))
			return (error_msg(ERR_MALLOC_8));
		new_room->next = NULL;
		if (*lst_rooms)
			tmp_link->next = new_room;
		else
			*lst_rooms = new_room;
		while (*find_end && ft_strcmp((*find_end)->room->name, ptr_end->prev_room))
			*find_end = (*find_end)->prev;
	}
	(*find_end) = ptr_end;
	return (1);
}

int		fill_path(int nb_path, t_queue **find_end, t_path **paths)
{
	t_path	*tmp_path;
	t_path	*new_path;

	tmp_path = (*paths);
	while (*paths && tmp_path->next)
		tmp_path = tmp_path->next;
	if (!(new_path = (t_path *)ft_memalloc(sizeof(t_path))))
		return (error_msg(ERR_MALLOC_5));
	new_path->nb_path = nb_path;
	new_path->lst_rooms = NULL;
	if (!(fill_lst_rooms(find_end, &(new_path->lst_rooms))))
		return (error_msg(ERR_MALLOC_6));
	new_path->next = NULL;
	if ((*paths))
		tmp_path->next = new_path;
	else
		(*paths) = new_path;
	return (1);
}

int		lemin(t_room **room, t_queue **queue, t_path **paths)
{
	t_room	*current_room;
	t_room	*room_to_push;
	t_queue	*queue_state;
	t_queue	*find_end;
	int		nb_path;

	nb_path = 0;
	current_room = NULL;
	room_to_push = NULL;
	find_end = NULL;
	if (!(init_bfs(room, queue, &current_room)))
		return (error_msg(ERR_MALLOC_4));
	queue_state = (*queue);
	while (bfs(room, &queue_state, &current_room, &room_to_push) == 1)
	{
		find_end = (find_end && find_end->next) ? find_end->next : (*queue);
		while (find_end && find_end->room->end != 1)
			find_end = find_end->next;
		if (!(fill_path(nb_path, &find_end, paths)))
			return (error_msg(ERR_MALLOC_9));
		nb_path++;
		//update_graph
		//check_result
		//proteger bfs?
		// return (1);
	}
	return (1);
}
