/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 00:24:01 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/28 00:48:55 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		helper_flr(t_queue **ptr_end, t_links **lst_rooms, t_queue **find_end)
{
	t_links		*new_room;
	t_links		*tmp_link;

	*ptr_end = (*find_end);
	tmp_link = (*lst_rooms);
	while (*lst_rooms && tmp_link->next)
		tmp_link = tmp_link->next;
	if (!(new_room = (t_links *)ft_memalloc(sizeof(t_links))))
		return (error_msg(ERR_MALLOC_7));
	if (!(new_room->room = ft_strdup((*find_end)->room->name)))
		return (error_msg(ERR_MALLOC_8));
	new_room->next = NULL;
	if (!(*lst_rooms))
		*lst_rooms = new_room;
	else
		tmp_link->next = new_room;
	return (1);
}

/*
** ==================== helper_flr ====================
** this function allocate and fill the room we add to the path
*/

static int		fill_lst_rooms(t_queue **find_end, t_links **lst_rooms)
{
	t_queue		*ptr_end;
	t_queue		*ptr_true_end;

	ptr_end = NULL;
	ptr_true_end = *find_end;
	while ((*find_end)->room->start != 1)
	{
		if (!(helper_flr(&ptr_end, lst_rooms, find_end)))
			return (error_msg(ERR_MALLOC_10));
		while (*find_end && ft_strcmp((*find_end)->room->name, ptr_end->prev_room))
			*find_end = (*find_end)->prev;
	}
	if (!(helper_flr(&ptr_end, lst_rooms, find_end)))
			return (error_msg(ERR_MALLOC_10));
	(*find_end) = ptr_true_end;
	return (1);
}

/*
** ==================== fill_lst_rooms ====================
** parse the queue in reverse order to know which rooms ->
** are part of the path and fill them into that last
** ptr_true_end is a pointer on the actual end ->
** after the path is filled find_end = ptr_true_end
*/

int				fill_path(int nb_path, t_queue **find_end, t_path **paths)
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

/*
** ==================== fill_path ====================
** put tmp_path on the last path
** allocate the new path and set his number
** call fill_lst_rooms that add all rooms that are part of the path to the path
** (path are filled going from end to start)
** if path exist, add the path at the end of the path list
** create path list with the first element
*/