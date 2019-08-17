/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 01:56:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/17 14:37:34 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int				del_room_in_path(t_path **current)
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

int				free_one_path(t_path **paths, t_path **current)
{
	t_path	*tmp;
	t_links	*buf;
	t_links	*index;

	tmp = (*paths);
	while (*paths && *current && tmp->next && tmp->next != *current)
		tmp = tmp->next;
	if (*current)
	{
		buf = (*current)->links;
		while (buf)
		{
			index = buf;
			ft_strdel(&(index->room));
			buf = buf->next;
			free(index);
		}
		free(*current);
		tmp->next = NULL;
	}
	return (1);
}

int				free_paths(t_path **paths, int var)
{
	t_path	*tmp;
	t_links	*links;
	t_links	*index;

	while (*paths)
	{
		tmp = (*paths);
		links = tmp->links;
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

int				free_all(t_room **rooms, t_ban **list, t_path **paths, int var)
{
	t_ban	*tmp;

	while (*rooms)
		free_rooms_and_links(rooms);
	while (*list)
	{
		tmp = (*list);
		ft_strdel(&(tmp->name));
		(*list) = (*list)->next;
		free(tmp);
	}
	if (*paths)
		free_paths(paths, var);
	if (var == 1)
		ft_putendl("ERROR");
	return (var);
}
