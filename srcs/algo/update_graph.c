/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:36:08 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/13 07:41:49 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		fill_path(t_lst_room **lst_rooms, t_links **links)
{
	t_links		*tmp_link;
	t_lst_room	*new_lst_room;
	t_lst_room	*tmp_lst_room;

	tmp_link = (*links);
	tmp_lst_room = (*lst_rooms);
	while (tmp_link && tmp_link->coming->end != 1)
	{
		new_lst_room = NULL;
		if (tmp_link->full == 1 && tmp_link->same_link->full != 1)
		{
			if (!(new_lst_room = (t_lst_room *)malloc(sizeof(t_lst_room))))
				return (error_msg(ERR_MALLOC_14));
			new_lst_room->next = NULL;
			new_lst_room->room = tmp_link->same_link->coming;
			tmp_lst_room->next = new_lst_room;
			tmp_lst_room = tmp_lst_room->next;
			tmp_link = tmp_link->same_link->coming->links;
		}
		else
			tmp_link = tmp_link->next;
	}
	return (1);
}

static	int		update_paths(t_links **links, t_path **updated_paths)
{
	t_path *new_path;
	t_path *tmp_path;

	new_path = NULL;
	tmp_path = *updated_paths;
    while (tmp_path && tmp_path->next)
		tmp_path = tmp_path->next;
	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (error_msg(ERR_MALLOC_12));
	if (!(new_path->lst_rooms = (t_lst_room *)malloc(sizeof(t_lst_room))))
		return (error_msg(ERR_MALLOC_12));
	new_path->lst_rooms->room = (*links)->coming;
	new_path->lst_rooms->next = NULL;
	new_path->next = NULL;
	if (!fill_path(&(new_path->lst_rooms), links))
		return (error_msg(ERR_MALLOC_13));
	if (!(*updated_paths))
		(*updated_paths) = new_path;
	else
		tmp_path->next = new_path;
	return (1);
}

/*
** ==================== update_path ====================
** 
*/

int				update_graph(t_lemin *l)
{
	t_path  *updated_paths;
	t_room  *find_start;
	t_links	*tmp_links;

	updated_paths = NULL;
	find_start = find_start_room(l);
	tmp_links = find_start->links;
	while (tmp_links)
	{
		if (tmp_links->full == 1)
			if (!update_paths(&(tmp_links), &updated_paths))
				return (error_msg(ERR_MALLOC_11));
		tmp_links = tmp_links->next;
	}
	l->path = updated_paths;
	return (1);
}

/*
** ==================== update_graph ====================
** 
*/


// static	int		fill_path(t_lst_room **lst_rooms, t_links **links)
// {
// 	static int i = 1;
// 	ft_printf("\x1b[36m==================== Call fill_path number %d ====================\x1b[0m\n", i);
// 	t_links		*tmp_link;
// 	t_lst_room	*new_lst_room;
// 	t_lst_room	*tmp_lst_room;

// 	tmp_link = (*links);
// 	tmp_lst_room = (*lst_rooms);
// 	while (tmp_link && tmp_link->coming->end != 1)
// 	{
// 		new_lst_room = NULL;
// 		// if (i == 2)
// 		// {
// 			if (tmp_link->full == 1 && tmp_link->same_link->full != 1)
// 			{
// 				ft_printf("\x1b[32m1- tmp_lst_room->name = %-5s\ttmp_link->room = %-5s\ttmp_link->full = %d\ttmp_link->same_link->full = %d\t\x1b[0m", tmp_lst_room->room->name, tmp_link->room, tmp_link->full, tmp_link->same_link->full);
// 				ft_printf("\x1b[31mswap => %s-%s\n\x1b[0m", tmp_link->room, tmp_link->same_link->coming->links->room);
// 			}
// 			else
// 				ft_printf("2- tmp_lst_room->name = %-5s\ttmp_link->room = %-5s\ttmp_link->full = %d\ttmp_link->same_link->full = %d\n", tmp_lst_room->room->name, tmp_link->room, tmp_link->full, tmp_link->same_link->full);
// 		// }
// 		if (tmp_link->full == 1 && tmp_link->same_link->full != 1)
// 		{
// 			if (!(new_lst_room = (t_lst_room *)malloc(sizeof(t_lst_room))))
// 				return (error_msg(ERR_MALLOC_14));
// 			new_lst_room->next = NULL;
// 			new_lst_room->room = tmp_link->same_link->coming;
// 			tmp_lst_room->next = new_lst_room;
// 			tmp_lst_room = tmp_lst_room->next;
// 			// if (i == 3)
// 				// ft_printf("tmp_lst_room->name = %s\n", tmp_lst_room->room->name);
// 			tmp_link = tmp_link->same_link->coming->links;
// 		}
// 		else
// 		// if (tmp_link && tmp_link->room && tmp_link->next && tmp_link->next->room && i == 3)
// 		// 	ft_printf("\x1b[31miterate => %s-%s\n\x1b[0m", tmp_link->room, tmp_link->next->room);
// 			tmp_link = tmp_link->next;
// 	}
// 	if (tmp_lst_room && tmp_lst_room->room && tmp_link && tmp_link->same_link && tmp_link->room)
// 		ft_printf("\x1b[32m3- tmp_lst_room->name = %-5s\ttmp_link->room = %-5s\ttmp_link->full = %d\ttmp_link->same_link->full = %d\n\x1b[0m", tmp_lst_room->room->name, tmp_link->room, tmp_link->full, tmp_link->same_link->full);
// 		// ft_printf("tmp_lst_room->name = %-5s\ttmp_link->room = %-5s\ttmp_link->full = %d\ttmp_link->same_link->full = %d\n", tmp_lst_room->room->name, tmp_link->room, tmp_link->full, tmp_link->same_link->full);
// 	i++;
// 	return (1);
// }
