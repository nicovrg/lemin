/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:35:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/20 03:21:56 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_path	*new_paths(t_path **current)
{
	t_links	*tmp;
	t_path	*new;

	tmp = (*current)->links;
	if (!(new = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	new->path = (*current)->path + 1;
	new->next = NULL;
	new->links = NULL;
	while (tmp && tmp->next)
	{
		if (!(add_room_in_path(&(new->links), tmp->room)))
			return (NULL);
		tmp = tmp->next;
	}
	(*current)->next = new;
	return (new);
}

int		parse_links(t_room **rooms, t_path **current, t_ban **list, t_links **links)
{
	while ((*links))
	{
		while ((*links) && (*links)->room
		&& (room_is_passed(current, (*links)->room)
		|| room_is_banned((*links)->room, list)))
			(*links) = (*links)->next;
		if ((*links) && (*links)->room
		&& !add_room_in_path(&((*current)->links), (*links)->room))
			return (0);
		if ((*links) && (*links)->room
		&& parse_paths(rooms, current, (*links)->room, list) == 1)
			*current = new_paths(current);
			// return (1);
		else if ((*links))
		{
			// if (!(fill_banned_rooms(list, (*links)->room)))
			// 	return (0);
			del_room_in_path(current);
		}
		if ((*links))
			(*links) = (*links)->next;
	}
	return (2);
}

/*
** ==================== parse_links ====================
** check if the room is passed or banned
** then add it to the current path
** then call parse_paths in recursive
** if we are in the end of a branch that not result
** of the end of the path then ban the room and delete the last
** room of the current path
*/

int		parse_paths(t_room **rooms, t_path **current, char *name, t_ban **list)
{
	t_room	*tmp;
	t_links	*links;

	tmp = (*rooms);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			if (tmp->end == 1)
				return (1);
			if (tmp->start == 1)
				return (2);
			links = tmp->links;
			if (!parse_links(rooms, current, list, &links))
				return (0);
			else
				return (2);
			// return (parse_links(rooms, current, list, &links));
		}
		tmp = tmp->next;
	}
	return (2);
}

int		check_paths(t_room **rooms, t_path **paths, t_ban **list)
{
	t_room	*tmp;
	t_path	*current;
	t_links	*buf;
	int		nb_path;
	int		j;

	nb_path = 1;
	tmp = (*rooms);
	while (tmp)
	{
		if (tmp->start == 1)
		{
			buf = tmp->links;
			while (buf)
			{
				if (!(current = init_paths(paths, nb_path, tmp->name)))
					return (0);
				if (!add_room_in_path(&(current->links), buf->room))
					return (0);
				j = parse_paths(rooms, &current, buf->room, list);
				if (j == 0)
					return (free_paths(paths, 0));
				if (j == 1)
					nb_path = current->path + 1;
				else
					nb_path = current->path;
				if (j == 2)
					free_one_path(paths, &current);
				buf = buf->next;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
