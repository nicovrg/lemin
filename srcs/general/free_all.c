/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 01:56:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/13 23:34:36 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int				free_paths(t_path **paths, int var)
{
	t_path	*tmp;
	t_links	*buf;
	t_links	*index;

	tmp = (*paths);
	buf = tmp->links;
	while (buf)
	{
		index = buf;
		ft_strdel(&(index->room));
		buf = buf->next;
		free(index);
	}
	(*paths) = (*paths)->next;
	free(tmp);
	return (var);
}

static int		free_rooms_and_links(t_room **rooms)
{
	t_room	*tmp;
	t_links	*buf;
	t_links	*index;

	tmp = (*rooms);
	buf = tmp->links;
	while (buf)
	{
		index = buf;
		ft_strdel(&(index->room));
		buf = buf->next;
		free(index);
	}
	(*rooms) = (*rooms)->next;
	ft_strdel(&(tmp->name));
	free(tmp);
	return (1);
}

int				free_all(t_room **rooms, int var)
{
	int		i;

	i = 0;
	while (*rooms)
		free_rooms_and_links(rooms);
	if (var == 1)
		ft_putendl("ERROR");
	return (var);
}
