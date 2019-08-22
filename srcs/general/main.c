/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/22 02:46:18 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		print_paths(t_path *paths)
{
	while (paths)
	{
		ft_printf("PATH = %d\n---------------------------------------------------\n", paths->path);
		while (paths->links)
		{
			ft_printf("LINK: %s\n", paths->links->room);
			paths->links = paths->links->next;
		}
		ft_printf("---------------------------------------------------\n\n\n\n");
		paths = paths->next;
	}
	return (1);
}

// int		print_rooms(t_room *rooms)
// {
// 	while (rooms)
// 	{
// 		ft_printf("ROOM = %s\nSTART = %d END = %d\n---------------------------------------------------\n",
// 		rooms->name, rooms->start, rooms->end);
// 		while (rooms->links)
// 		{
// 			ft_printf("TUBE : %s\n", rooms->links->room);
// 			rooms->links = rooms->links->next;
// 		}
// 		ft_printf("---------------------------------------------------\n\n\n\n");
// 		rooms = rooms->next;
// 	}
// 	return (1);
// }

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
		return (free_all(&rooms, &tab, &paths, 1));
	if (!check_map_validity(&rooms))
		return (free_all(&rooms, &tab, &paths, 1));
	if (!lemin(&rooms, &queue))
		return (free_all(&rooms, &tab, &paths, 1));
	// if (!check_paths(&rooms, &paths, &list))
	// 	return (free_all(&rooms, &list, &paths, 1));
	// print_paths(paths);
	ft_putendl("FINISH");
	free_queue(&queue);
	free_all(&rooms, &tab, &paths, 0);
	return (0);
}

/*
** ==================== main ====================
** call check_line() -> parse data and store it
** call check_map_validity() -> check if the map is valid
*/
