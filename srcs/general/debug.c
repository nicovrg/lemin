/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:54:42 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/03 04:20:26 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		print_queue(t_queue **queue)
{
	while (*queue)
	{
		ft_printf("QUEUE = %s\n", (*queue)->room->name);
		(*queue) = (*queue)->next;
	}
	return (1);
}

int		print_paths(t_path **paths)
{
	t_path	*tmp_path;
	t_links	*tmp_links;

	tmp_path = (*paths);
	while (tmp_path)
	{
		ft_printf("PATH = %d\n---------------------------------------------------\n", tmp_path->nb_path);
		tmp_links = tmp_path->lst_rooms;
		while (tmp_links)
		{
			ft_printf("LINK: %s\n", tmp_links->room);
			tmp_links = tmp_links->next;
		}
		ft_printf("---------------------------------------------------\n\n\n\n");
		tmp_path = tmp_path->next;
	}
	return (1);
}

int		print_rooms(t_room **rooms)
{
	t_room	*tmp_room;
	t_links	*tmp_links;

	tmp_room = (*rooms);
	while (tmp_room)
	{
		ft_printf("ROOM = %s\nSTART = %d END = %d\n---------------------------------------------------\n",
		tmp_room->name, tmp_room->start, tmp_room->end);
		tmp_links = tmp_room->links;
		while (tmp_links)
		{
			ft_printf("TUBE : %s\t%d\n", tmp_links->room, tmp_links->discovered);
			tmp_links = tmp_links->next;
		}
		ft_printf("---------------------------------------------------\n\n\n\n");
		tmp_room = tmp_room->next;
	}
	return (1);
}
