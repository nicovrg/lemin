/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:35:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/14 01:21:14 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_is_passed(t_path **current, char *name)
{
	t_links	*tmp;

	tmp = (*current)->links;
	while (tmp)
	{
		if (!ft_strcmp(tmp->room, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		parse_paths(t_room **rooms, t_path **current, char *name)
{
	t_room	*tmp;
	t_links	*links;
	t_links	*buf;

	buf = (*current)->links;
	tmp = (*rooms);
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			if (tmp->end == 1)
				return (1);
			links = tmp->links;
			while (links && room_is_passed(current, links->room))
				links = links->next;
			if (!add_room_in_path(&buf, links->room))
				return (0);
			if (parse_paths(rooms, current, links->room))
				return (1);
		}
		tmp = tmp->next;
	}
	return (2);
}

int		check_paths(t_room **rooms, t_path **paths)
{
	t_room	*tmp;
	t_path	*current;
	t_links	*buf;
	int		i;
	int		j;

	i = 1;
	tmp = (*rooms);
	while (tmp)
	{
		if (tmp->start == 1)
		{
			buf = tmp->links;
			while (buf)
			{
				if (!(current = init_paths(paths, i, tmp->name)))
					return (0);
				if (!add_room_in_path(&(current->links), buf->room))
					return (0);
				j = parse_paths(rooms, &current, buf->room);
				if (j == 0)
					return (free_paths(paths, 0));
				if (j == 1)
					i++;
				if (j == 2)
					free_paths(paths, 1);
				buf = buf->next;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
