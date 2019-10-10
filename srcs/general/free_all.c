/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 01:56:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/10/10 14:15:55 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int				free_paths(t_path **paths)
{
	t_path		*tmp_path;
	t_lst_room	*tmp_lst_room;
	t_lst_room	*lst_room;

	while (*paths)
	{
		tmp_path = (*paths);
		lst_room = tmp_path->lst_rooms;
		while (lst_room)
		{
			tmp_lst_room = lst_room;
			lst_room = lst_room->next;
			free(tmp_lst_room);
		}
		(*paths) = (*paths)->next;
		free(tmp_path);
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
	if (l->path)
		free_paths(&(l->path));
	while (l->room)
		free_rooms_and_links(&(l->room));
	while (l->tab && l->tab[i])
	{
		ft_strdel(&((l->tab)[i]));
		i++;
	}
	free(l->tab);
	if (var == 1)
		ft_putendl("ERROR");
	return (0);
}
