/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 05:44:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/19 04:20:00 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		print_ant(int ant, char *room_name, t_lemin *l)
{
	addchar_buff(0, 'L', l);
	addnbr_buff(ant, l);
	addchar_buff(0, '-', l);
	addstr_buff(room_name, l);
	return (1);
}

int		print_tab(t_lemin *l)
{
	int		index_tab;

	index_tab = 0;
	while (l->tab[index_tab])
	{
		ft_putendl(l->tab[index_tab]);
		index_tab++;
	}
	ft_putchar('\n');
	return (1);
}

int		print_moves(t_lemin *l)
{
	l->stock = l->nb_ant;
	while (l->stock)
	{
		if (l->stock != l->nb_ant)
			swap_ants(l);
		move_from_start(l);
		if (l->check_newline == 1)
			addchar_buff(0, '\n', l);
		l->check_newline = 0;
	}
	while (still_ants_in_path(l))
	{
		swap_ants(l);
		if (l->check_newline == 1)
			addchar_buff(0, '\n', l);
		l->check_newline = 0;
	}
	return (1);
}

int		print_render(t_lemin *l)
{
	print_tab(l);
	print_moves(l);
	addchar_buff(1, 0, l);
	return (1);
}
