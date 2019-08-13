/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:35:58 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/13 03:21:29 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		init_paths(t_room **paths, char *str)
{
	t_room	*tmp;
	t_room	*new;

	tmp = (*paths);
	while (*paths && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	if (!(new->name = ft_strdup(str)))
		return (0);
	new->next = NULL;
	new->links = NULL;
	if (!(*paths))
		(*paths) = new;
	else
		tmp->next = new;
	return (1);
}

// int		parse_the_path(t_room **tmp)
// {
// 	t_links	*buf;

// 	buf = (*tmp);
// 	return (1);
// }

int		check_paths(t_room **rooms, t_room **paths)
{
	t_room	*tmp;

	tmp = (*rooms);
	while (tmp)
	{
		if (tmp->start == 1)
		{
			if (!(init_paths(paths, tmp->name)))
				return (0);
			// parse_the_path(&tmp);
		}
		tmp = tmp->next;
	}
	return (1);
}
