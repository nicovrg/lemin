/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/10/09 09:08:55 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include "time_exe.h"

static	int		init_main(t_lemin *l)
{
	l->nb_ant = 0;
	l->temp_render = 0;
	l->shortest_path = 0;
	l->stock = 0;
	l->max_paths = 0;
	l->check_space = 0;
	l->check_newline = 0;
	l->index_buff = 0;
	l->room = NULL;
	l->path = NULL;
	l->queue = NULL;
	l->tab = NULL;
	ft_bzero(&(l->buff), BUFF_SIZE);
	return (1);
}

int				main(void)
{
	t_lemin lem;

	init_main(&lem);
	time_exe("parsing - check_lines");
	if (!check_lines(&lem))
		return (free_all(1, &lem));
	time_exe("parsing - check_map_validity");
	if (!check_map_validity(&lem))
		return (free_all(1, &lem));
	time_exe("algo - lemin");
	if (!lemin(&lem))
		return (free_all(1, &lem));
	time_exe("print / free");	
	if (!(lem.path))
		return (free_all(1, &lem));
	print_render(&lem);
	free_all(0, &lem);
	print_time();
	return (0);
}

/*
** ==================== main ====================
** call check_line() -> parse data and store it
** call check_map_validity() -> check if the map is valid
*/
