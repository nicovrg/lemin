/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/03 04:21:09 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		main(void)
{
	int		nb_ant;
	char	**tab;
	t_room	*rooms;
	t_path	*paths;
	t_queue *queue;

	nb_ant = 0;
	tab = NULL;
	rooms = NULL;
	paths = NULL;
	queue = NULL;
	if (!check_lines(&rooms, &nb_ant, &tab))
		return (free_error(&rooms, &tab, &paths, &queue));
	if (!check_map_validity(&rooms))
		return (free_error(&rooms, &tab, &paths, &queue));
	if (!lemin(&rooms, &queue, &paths))
		return (free_error(&rooms, &tab, &paths, &queue));
	// if (!check_paths(&rooms, &paths, &list))
	//	return (free_all(&rooms, &list, &paths, 1));
	// print_paths(&paths);
	print_rooms(&rooms);
	ft_putendl("FINISH");
	free_all(&rooms, &tab, &paths, &queue);
	return (0);
}

/*
** ==================== main ====================
** call check_line() -> parse data and store it
** call check_map_validity() -> check if the map is valid
*/
