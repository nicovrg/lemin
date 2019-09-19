/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:54:42 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/19 20:11:48 by nivergne         ###   ########.fr       */
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
	char		*norme;
	t_path		*tmp_path;
	t_lst_room	*tmp_lst_room;

	tmp_path = *paths;
	while (tmp_path)
	{
		tmp_lst_room = tmp_path->lst_rooms;
		ft_printf("\x1b[35m================== PATH ================\n\x1b[0m");
		ft_printf("STOP_ANTS = %d\n", tmp_path->stop_ants);
		while (tmp_lst_room)
		{
			norme = tmp_lst_room->room->name;
			ft_printf("\x1b[35mPTR_ROOM = %s\n\x1b[0m", norme);
			tmp_lst_room = tmp_lst_room->next;
		}
		ft_printf("\x1b[35m=======================================\n\n\x1b[0m");
		tmp_path = tmp_path->next;
	}
	return (1);
}

int		print_rooms(t_lemin *l)
{
	t_room	*tmp_room;
	t_links	*tmp_links;

	tmp_room = l->room;
	while (tmp_room)
	{
		ft_printf("ROOM = %s", tmp_room->name);
		ft_printf(" START = %d", tmp_room->start);
		ft_printf(" END = %d\n", tmp_room->end);
		ft_printf("-----------------------------------------\n");
		tmp_links = tmp_room->links;
		while (tmp_links)
		{
			ft_printf("TUBE : %s\t%d\n", tmp_links->room, tmp_links->full);
			tmp_links = tmp_links->next;
		}
		ft_printf("-----------------------------------------\n\n\n\n");
		tmp_room = tmp_room->next;
	}
	return (1);
}
