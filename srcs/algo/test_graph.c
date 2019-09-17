/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 08:46:17 by nicolasv          #+#    #+#             */
/*   Updated: 2019/09/17 04:51:26 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// int		still_ants_in_path(t_lemin *l)
// {
// 	t_path		*tmp_path;
// 	t_lst_room	*tmp_lst_room;

// 	tmp_path = l->path;
// 	while (tmp_path)
// 	{
// 		tmp_lst_room = tmp_path->lst_rooms->next;
// 		while (tmp_lst_room)
// 		{
// 			if (tmp_lst_room->room->ant != 0)
// 				return (1);
// 			tmp_lst_room = tmp_lst_room->next;
// 		}
// 		tmp_path = tmp_path->next;
// 	}
// 	return (0);
// }

// int		move_from_start(t_lemin *l, int *ret)
// {
// 	t_path *tmp_path;

// 	tmp_path = l->path;
// 	while (tmp_path)
// 	{
// 		l->stock--;
// 		tmp_path->lst_rooms->next->room->ant = l->nb_ant - l->stock;
// 		(*ret)++;
// 		// ft_printf("room: %s\tant: %d\n", tmp_path->lst_rooms->next->room->name, tmp_path->lst_rooms->next->room->ant);
// 		tmp_path = tmp_path->next;
// 	}
// 	return (1);
// }

// int		swap_ants(t_lemin *l)
// {
// 	static int i = 1;
// 	ft_printf("\x1b[34m==================== CALL %d ====================\n\x1b[0m", i++);
// 	int			tmp_ant1;
// 	int			tmp_ant2;
// 	t_path		*tmp_path;
// 	t_lst_room	*tmp_lst_room;

// 	tmp_ant1 = 0;
// 	tmp_ant2 = 0;
// 	tmp_path = l->path;
// 	while (tmp_path)
// 	{
// 		tmp_lst_room = tmp_path->lst_rooms->next;
// 		while (tmp_lst_room)
// 		{
// 			if (!tmp_ant1)
// 			{
// 				tmp_ant1 = tmp_lst_room->room->ant;
// 				tmp_lst_room->room->ant = 0;
// 			}
// 			else
// 				tmp_ant1 = tmp_ant2;
// 			ft_printf("room: %-5s\tant: %d\n", tmp_lst_room->room->name, tmp_lst_room->room->ant);			
// 			tmp_lst_room = tmp_lst_room->next;
// 			if (tmp_lst_room)
// 			{
// 				tmp_ant2 = tmp_lst_room->room->ant;
// 				tmp_lst_room->room->ant = tmp_ant1;
// 			}
// 		}
// 		ft_printf("\n");
// 		tmp_path = tmp_path->next;		
// 	}
// 	return (1);
// }

int		check_length_paths(t_lemin *l, t_path **updated_path)
{
	t_path	*tmp_path;

	tmp_path = (*updated_path);
	while (tmp_path)
	{
		if (l->stock > tmp_path->length || tmp_path->length == l->shortest_path)
			l->stock--;
		tmp_path = tmp_path->next;
	}
	return (1);
}

long	test_graph(t_lemin *l, t_path **updated_path)
{
	long	ret;

	ret = 0;
	l->stock = l->nb_ant;
	while (l->stock > 0)
	{
		check_length_paths(l, updated_path);
		ret++;
	}
	ret = ret + l->shortest_path - 1;
	return (ret);
/*
** ==================== test_graph ====================
** 
	int		ret;
	int		sent;

	ret = 0;
	sent = 0;
	l->stock = l->nb_ant;
	print_paths(&l->path);
	while (l->stock)
	{
		if (ret > 0)
			swap_ants(l);
		move_from_start(l, &ret);
		sent++;
		//déplacer toutes les fourmis dans leurs liens suivants
		//compter le nb de mouvements pour decrementer le stock
	}
	while (still_ants_in_path(l))
	{
		swap_ants(l);
		ret++;
	}
	ft_printf("RETOUR = %d\n", ret);
	ft_printf("SENT = %d\n", sent);
	//tant que on peut
		//déplacer toutes les fourmis dans leurs liens suivants
		//compter le nb de mouvements pour decrementer le stock
	return (1);
*/
}
