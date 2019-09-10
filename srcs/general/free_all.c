/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 01:56:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/10 03:22:25 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int				free_paths(t_path **paths)
{
	t_path	*tmp;
	t_links	*links;
	t_links	*index;

	while (*paths)
	{
		tmp = (*paths);
		links = tmp->lst_rooms;
		while (links)
		{
			index = links;
			ft_strdel(&(index->room));
			links = links->next;
			free(index);
		}
		(*paths) = (*paths)->next;
		free(tmp);
	}
	return (1);
}

static int		free_rooms_and_links(t_room **rooms)
{
	t_room	*tmp;
	t_links	*buf;
	t_links	*index;

	tmp = (*rooms);
	buf = tmp->links;
	while (tmp && buf)
	{
		index = buf;
		ft_strdel(&(index->room));
		ft_strdel(&(index->coming));
		buf = buf->next;
		free(index);
	}
	(*rooms) = (*rooms)->next;
	ft_strdel(&(tmp->name));
	free(tmp);
	return (1);
}

int				free_queue(t_queue **queue)
{
	t_queue *tmp;

	while (*queue)
	{
		tmp = (*queue);
		(*queue) = (*queue)->next;
		free(tmp);
	}
	return (1);
}

int				free_all(int var, t_lemin *l)
{
	int	i;

	i = 0;
	if (l->queue)
		free_queue(&(l->queue));
	while (l->room)
		free_rooms_and_links(&(l->room));
	while (l->tab && l->tab[i])
	{
		ft_strdel(&((l->tab)[i]));
		i++;
	}
	if (l->tab)
		(free(l->tab));
	if (l->path)
		free_paths(&(l->path));
	if (var == 1)
		ft_putendl("ERROR");
	return (0);
}
