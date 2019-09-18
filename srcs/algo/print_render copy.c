/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 05:44:32 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/18 21:44:25 by nivergne         ###   ########.fr       */
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
		if (l->stock > tmp_path->length || tmp_path->length == l->final_short_path)
		{
			l->stock--;
			tmp_path->lst_rooms->next->room->ant = l->nb_ant - l->stock;
			ft_printf("L%d-%s ", tmp_path->lst_rooms->next->room->ant, tmp_path->lst_rooms->next->room->name);
		}
		tmp_path = tmp_path->next;
	}
	return (1);
}

int		swap_ants(t_lemin *l)
{
	int			tmp_ant1;
	t_path		*tmp_path;
	t_lst_room	*tmp_lst_room;

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
				ft_printf("L%d-%s ", tmp_ant1, tmp_lst_room->next->room->name);
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
	int		index_buff;
	char	buff[BUFF_SIZE];

	index_buff = 0;
	ft_bzero(buff, BUFF_SIZE);
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
	print_tab(l);
	print_moves(l);
	return (1);
}