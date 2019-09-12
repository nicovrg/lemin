/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/13 00:22:47 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static	int		init_main(t_lemin *l)
{
	l->nb_ant = 0;
	l->max_paths = 0;
	l->room = NULL;
	l->path = NULL;
	l->queue = NULL;
	l->tab = NULL;
	return (1);
}

int				main(void)
{
	t_lemin lem;

	init_main(&lem);
	if (!check_lines(&lem))
		return (free_all(1, &lem));
	if (!check_map_validity(&lem))
		return (free_all(1, &lem));
	if (!lemin(&lem))
		return (free_all(1, &lem));
	// print_rooms(&lem);
	print_paths(&lem.path);
	ft_putendl("FINISH");
	free_all(0, &lem);
	return (0);
}

/*
** ==================== main ====================
** call check_line() -> parse data and store it
** call check_map_validity() -> check if the map is valid
*/
