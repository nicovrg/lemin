/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/10 00:41:20 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static	int		init_main(t_lemin *l)
{
	l->nb_ant = 0;
	l->max_paths = 0;
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
	t_lemin lem;

	init_main(&lem);
	init_main_two(&lem);
	if (!check_lines(&lem))
		return (free_all(1, &lem));
	if (!check_map_validity(&lem))
		return (free_all(1, &lem));
	if (!lemin(&lem))
		return (free_all(1, &lem));
	if (!lem.path)
		return (free_all(1, &lem));
	// print_paths(&lem.path);
	print_rooms(&lem);
	ft_putendl("FINISH");
	free_all(0, &lem);
	return (0);
}

/*
** ==================== main ====================
** call check_line() -> parse data and store it
** call check_map_validity() -> check if the map is valid
*/
