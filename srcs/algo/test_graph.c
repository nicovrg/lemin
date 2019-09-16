/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 08:46:17 by nicolasv          #+#    #+#             */
/*   Updated: 2019/09/14 06:14:52 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		move_from_start(t_lemin *l)
{
	t_path *tmp_path;

	tmp_path = l->path;
	while (tmp_path)
	{
		l->stock--;
		tmp_path->lst_rooms->next->room->ant = l->nb_ant - l->stock;
		// ft_printf("room: %s\tant: %d\n", tmp_path->lst_rooms->next->room->name, tmp_path->lst_rooms->next->room->ant);
		tmp_path = tmp_path->next;
	}
	return (1);
}

int		swap_ants(t_lemin *l)
{
	static int i = 1;
	ft_printf("\x1b[34m==================== CALL %d ====================\n\x1b[0m", i++);
	int			ret;
	int			tmp_ant1;
	int			tmp_ant2;
	t_path		*tmp_path;
	t_lst_room	*tmp_lst_room;

	ret = 0;
	tmp_ant1 = 0;
	tmp_path = l->path;
	while (tmp_path)
	{
		tmp_lst_room = tmp_path->lst_rooms->next;
		while (tmp_lst_room)
		{
			ft_printf("room: %-5s\tant: %d\n", tmp_lst_room->room->name, tmp_lst_room->room->ant);
			if (!tmp_ant1)
			{
				tmp_ant1 = tmp_lst_room->room->ant;
				tmp_lst_room->room->ant = 0;
			}
			tmp_lst_room = tmp_lst_room->next;
			if (tmp_lst_room)
			{
				tmp_ant2 = tmp_lst_room->room->ant;
				tmp_lst_room->room->ant = tmp_ant1;
				tmp_ant1 = tmp_ant2;
				ret++;
			}
		}
		ft_printf("\n");
		tmp_path = tmp_path->next;		
	}
	return (ret);
}

int		test_graph(t_lemin *l)
{
	l->stock = l->nb_ant;
	print_paths(&l->path);
	while (l->stock)
	{
		swap_ants(l);
		move_from_start(l);
		//déplacer toutes les fourmis dans leurs liens suivants
		//compter le nb de mouvements pour decrementer le stock
	}
	//tant que on peut 
		//déplacer toutes les fourmis dans leurs liens suivants
		//compter le nb de mouvements pour decrementer le stock
	return (1);
}
