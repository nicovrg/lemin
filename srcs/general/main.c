/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/04 03:53:22 by nivergne         ###   ########.fr       */
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
	if (!paths)
		return (free_error(&rooms, &tab, &paths, &queue));
	print_paths(&paths);
	// print_rooms(&rooms);
	ft_putendl("FINISH");
	free_all(&rooms, &tab, &paths, &queue);
	return (0);
}

/*
** ==================== main ====================
** call check_line() -> parse data and store it
** call check_map_validity() -> check if the map is valid
*/
