/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 04:19:39 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/19 04:31:15 by qgirard          ###   ########.fr       */
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
	int		i;
	t_path	*tmp_path;

	i = 0;
	tmp_path = l->path;
	while (tmp_path)
	{
		if (l->stock > tmp_path->stop_ants)
		{
			if (i > 0 || l->check_space == 1)
				addchar_buff(0, ' ', l);
			i++;
			l->stock--;
			tmp_path->lst_rooms->next->room->ant = l->nb_ant - l->stock;
			print_ant(tmp_path->lst_rooms->next->room->ant,
			tmp_path->lst_rooms->next->room->name, l);
			l->check_newline = 1;
		}
		tmp_path = tmp_path->next;
	}
	return (1);
}

int		print_the_swap(t_lemin *l, int *i, int *tmp_ant1,
t_lst_room **tmp_lst_room)
{
	if (*i > 0)
		addchar_buff(0, ' ', l);
	(*i)++;
	print_ant(*tmp_ant1, (*tmp_lst_room)->next->room->name, l);
	l->check_space = 1;
	l->check_newline = 1;
	return (1);
}

int		swap_ants(t_lemin *l)
{
	int			i;
	int			tmp_ant1;
	t_path		*tmp_path;
	t_lst_room	*tmp_lst_room;

	i = 0;
	tmp_ant1 = 0;
	tmp_path = l->path;
	while (tmp_path)
	{
		tmp_lst_room = tmp_path->lst_rooms->next;
		while (tmp_lst_room)
		{
			if (tmp_lst_room->room->end == 1)
				tmp_lst_room->room->ant = 0;
			ft_swap_ints(&tmp_ant1, &(tmp_lst_room->room->ant));
			if (tmp_ant1 && tmp_lst_room->next)
				print_the_swap(l, &i, &tmp_ant1, &tmp_lst_room);
			tmp_lst_room = tmp_lst_room->next;
		}
		tmp_path = tmp_path->next;
	}
	return (1);
}
