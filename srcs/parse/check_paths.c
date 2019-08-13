/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:35:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/13 22:18:12 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_paths(t_path **paths, int i)
{
	t_path	*tmp;
	t_path	*new;

	tmp = (*paths);
	while (*paths && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_path *)malloc(sizeof(t_path))))
		return (0);
	new->path = i;
	new->next = NULL;
	new->links = NULL;
	if (!(*paths))
		(*paths) = new;
	else
		tmp->next = new;
	return (1);
}

// int		parse_paths(t_room **rooms, t_path **paths)
// {
// 	return (1);
// }

int		check_paths(t_room **rooms, t_path **paths)
{
	t_room	*tmp;
	t_links	*buf;
	// t_path	*current;
	int		i;
	// int		j;

	i = 1;
	tmp = (*rooms);
	while (tmp)
	{
		if (tmp->start == 1)
		{
			buf = tmp->links;
			while (buf)
			{
				if (!(init_paths(paths, i)))
					return (0);
				// j = parse_paths(rooms, paths);
				buf = buf->next;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
