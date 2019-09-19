/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_renderrrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 05:44:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/19 02:19:19 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int 	print_ant(int ant, char *room_name, t_lemin *l)
{
	addchar_buff(0, 'L', l);
	addnbr_buff(ant, l);
	addchar_buff(0, '-', l);
	addstr_buff(room_name, l);
	return (1);
}

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
	i = 0;
	while (tmp_path)
	{
		if (l->stock > tmp_path->stop_ants)
		{
			if (i > 0 || l->check_space == 1)
				addchar_buff(0, ' ', l);
			i++;
			l->stock--;
			tmp_path->lst_rooms->next->room->ant = l->nb_ant - l->stock;
			print_ant(tmp_path->lst_rooms->next->room->ant, tmp_path->lst_rooms->next->room->name, l);
			// ft_printf("L%d-%s ", tmp_path->lst_rooms->next->room->ant, tmp_path->lst_rooms->next->room->name);
		}
		tmp_path = tmp_path->next;
	}
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
	i = 0;
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
			{
				if (i > 0)
					addchar_buff(0, ' ', l);
				i++;
				print_ant(tmp_ant1, tmp_lst_room->next->room->name, l);
				// ft_printf("L%d-%s ", tmp_ant1, tmp_lst_room->next->room->name);
				l->check_space = 1;
			}
			tmp_lst_room = tmp_lst_room->next;
		}
		tmp_path = tmp_path->next;		
	}
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
		addchar_buff(0, '\n', l);
		// ft_putendl("");
	}
	while (still_ants_in_path(l))
	{
		swap_ants(l);
		addchar_buff(0, '\n', l);
		// ft_putendl("");
	}
	l->buff[l->index_buff - 1] = 0;
	return (1);
}

int		print_render(t_lemin *l)
{
	print_tab(l);
	print_moves(l);
	addchar_buff(1, 0, l);
	// ft_putendl("coucou");
	return (1);
}
