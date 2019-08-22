/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 01:56:55 by qgirard           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/22 01:31:16 by qgirard          ###   ########.fr       */
=======
/*   Updated: 2019/08/22 02:45:53 by nivergne         ###   ########.fr       */
>>>>>>> b80c5a994f36fca3df678a78bc7f88d92c07ba8c
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

<<<<<<< HEAD
int				free_queue(t_queue **queue)
=======
int		free_queue(t_queue **queue)
>>>>>>> b80c5a994f36fca3df678a78bc7f88d92c07ba8c
{
	t_queue *tmp;

	while (*queue)
	{
		tmp = (*queue);
		free_rooms_and_links(&(tmp->room));
		(*queue) = (*queue)->next;
		free(tmp);
	}
	return (1);
}

int				free_all(t_room **rooms, char ***tab, t_path **paths, int var)
{
	int		i;

	i = 0;
	while (*rooms)
		free_rooms_and_links(rooms);
<<<<<<< HEAD
	while (*tab && (*tab)[i])
=======
	while ((*tab) && (*tab)[i])
>>>>>>> b80c5a994f36fca3df678a78bc7f88d92c07ba8c
	{
		ft_strdel(&((*tab)[i]));
		i++;
	}
	if (*tab)
		free(*tab);
	if (*paths)
		free_paths(paths, var);
	if (var == 1)
		ft_putendl("ERROR");
	return (var);
}
