/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 05:44:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/17 06:11:30 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		still_ants_in_path(t_lemin *l)
{
	t_path		*tmp_path;
	t_lst_room	*tmp_lst_room;

	tmp_path = l->path;
	while (tmp_path)
	{
		tmp_lst_room = tmp_path->lst_rooms->next;
		while (tmp_lst_room)
		{
			if (tmp_lst_room->room->ant != 0)
				return (1);
			tmp_lst_room = tmp_lst_room->next;
		}
		tmp_path = tmp_path->next;
	}
	return (0);
}

int		move_from_start(t_lemin *l)
{
	t_path *tmp_path;

	tmp_path = l->path;
	while (tmp_path)
	{
		l->stock--;
		tmp_path->lst_rooms->next->room->ant = l->nb_ant - l->stock;
		ft_printf("L%d-%s ", tmp_path->lst_rooms->next->room->ant, tmp_path->lst_rooms->next->room->name);
		// ft_printf("room: %s\tant: %d\n", tmp_path->lst_rooms->next->room->name, tmp_path->lst_rooms->next->room->ant);
		tmp_path = tmp_path->next;
	}
	return (1);
}

int		swap_ants(t_lemin *l)
{
	int			tmp_ant1;
	int			tmp_ant2;
	t_path		*tmp_path;
	t_lst_room	*tmp_lst_room;

	tmp_ant1 = 0;
	tmp_ant2 = 0;
	tmp_path = l->path;
	while (tmp_path)
	{
		tmp_lst_room = tmp_path->lst_rooms->next;
		while (tmp_lst_room)
		{
			if (!tmp_ant1)
			{
				tmp_ant1 = tmp_lst_room->room->ant;
				tmp_lst_room->room->ant = 0;
			}
			else
				tmp_ant1 = tmp_ant2;
			tmp_lst_room = tmp_lst_room->next;
			if (tmp_lst_room)
			{
				tmp_ant2 = tmp_lst_room->room->ant;
				tmp_lst_room->room->ant = tmp_ant1;
				if (tmp_lst_room->room->ant)
					ft_printf("L%d-%s ", tmp_lst_room->room->ant, tmp_lst_room->room->name);
			}
		}
		tmp_path = tmp_path->next;		
	}
	return (1);
}

int		print_moves(t_lemin *l)
{
	l->stock = l->nb_ant;
	while (l->stock)
	{
		swap_ants(l);
		move_from_start(l);
		ft_putchar('\n');
	}
	while (still_ants_in_path(l))
	{
		swap_ants(l);
		ft_putchar('\n');
	}
	return (1);
}

int		print_render(t_lemin *l)
{
	int		i;

	i = 0;
	while (l->tab[i])
	{
		ft_putendl(l->tab[i]);
		i++;
	}
	ft_putchar('\n');
	print_moves(l);
	return (1);
}