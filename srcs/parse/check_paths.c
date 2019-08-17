/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:35:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/17 13:25:51 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		del_room_in_path(t_path **current)
{
	t_links	*tmp;
	t_links	*ptr;

	tmp = (*current)->links;
	ptr = (*current)->links;
	while ((*current)->links && tmp->next)
		tmp = tmp->next;
	while ((*current)->links && ptr->next && ptr->next != tmp)
		ptr = ptr->next;
	if (tmp && tmp->room)
		ft_strdel(&(tmp->room));
	ptr->next = NULL;
	if (tmp)
		free(tmp);
	return (1);
}

/*
** ==================== del_room_in_path ====================
** delete the last room on the current path
*/

int		room_is_banned(char *name, t_ban **list)
{
	t_ban	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
** ==================== room_is_banned ====================
** check if the room is in the list of banned rooms
*/

int		room_is_passed(t_path **current, char *name)
{
	t_links	*tmp;

	tmp = (*current)->links;
	while (tmp)
	{
		if (tmp->room && !ft_strcmp(tmp->room, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
** ==================== room_is_passed ====================
** check if the room is already in the current path
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
			links = tmp->links;
			while (links)
			{
				while (links && links->room
				&& (room_is_passed(current, links->room) || room_is_banned(links->room, list)))
					links = links->next;
				if (links && links->room && !add_room_in_path(&((*current)->links), links->room))
					return (0);
				if (links && links->room && parse_paths(rooms, current, links->room, list) == 1)
					return (1);
				else if (links)
				{
					if (!(fill_banned_rooms(list, links->room)))
						return (0);
					del_room_in_path(current);
				}
				if (links)
					links = links->next;
			}
			if (!links)
				return (2);
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
					nb_path++;
				if (j == 2)
					free_one_path(paths, &current);
				buf = buf->next;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
