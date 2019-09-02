/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:54:42 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/02 23:13:56 by qgirard          ###   ########.fr       */
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

int		print_paths(t_path *paths)
{
	while (paths)
	{
		ft_printf("PATH = %d\n---------------------------------------------------\n", paths->nb_path);
		while (paths->lst_rooms)
		{
			ft_printf("LINK: %s\n", paths->lst_rooms->room);
			paths->lst_rooms = paths->lst_rooms->next;
		}
		ft_printf("---------------------------------------------------\n\n\n\n");
		paths = paths->next;
	}
	return (1);
}

int		print_rooms(t_room *rooms)
{
	while (rooms)
	{
		ft_printf("ROOM = %s\nSTART = %d END = %d\n---------------------------------------------------\n",
		rooms->name, rooms->start, rooms->end);
		while (rooms && rooms->links)
		{
			ft_printf("TUBE : %s\n", rooms->links->room);
			rooms->links = rooms->links->next;
		}
		ft_printf("---------------------------------------------------\n\n\n\n");
		rooms = rooms->next;
	}
	return (1);
}
