/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/05 02:23:50 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static	int		init_main(t_lemin *l)
{
	l->nb_ant = 0;
	l->zelda = NULL;
	return (1);
}

static int		init_main_two(t_lemin *l)
{
	l->tab = NULL;
	l->room = NULL;
	l->path = NULL;
	l->queue = NULL;
	return (1);
}

int				main(void)
{
	t_lemin l;

	init_main(&l);
	init_main_two(&l);
	if (!check_lines(&l))
		return (free_error(&l.room, &l.tab, &l.path, &l.queue));
	if (!check_map_validity(&l))
		return (free_error(&l.room, &l.tab, &l.path, &l.queue));
	if (!lemin(&l))
		return (free_error(&l.room, &l.tab, &l.path, &l.queue));
	if (!l.path)
		return (free_error(&l.room, &l.tab, &l.path, &l.queue));
	// print_paths(&l.path);
	print_rooms(&l);
	ft_putendl("FINISH");
	free_all(&l.room, &l.tab, &l.path, &l.queue);
	return (0);
}

/*
** ==================== main ====================
** call check_line() -> parse data and store it
** call check_map_validity() -> check if the map is valid
*/
