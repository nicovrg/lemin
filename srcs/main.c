/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/11 22:59:00 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

// int		print_rooms(t_room **room)
// {
	// while (rooms)
	// {
	// 	ft_printf("ROOM = %s\n---------------------------------------------------\n", rooms->name);
	// 	while (rooms->links)
	// 	{
	// 		ft_printf("TUBE : %s\n", rooms->links->room);
	// 		rooms->links = rooms->links->next;
	// 	}
	// 	ft_printf("---------------------------------------------------\n\n\n\n");
	// 	rooms = rooms->next;
	// }
	// return (1);
// }

int		main(int argc, char **argv)
{
	char	**tab;
	t_room	*rooms;

	tab = NULL;
	rooms = NULL;
	if (!check_lines(&rooms, &tab))
		return (free_all(&rooms, &tab, 1));
	if (!check_map_validity(&rooms))
		return (free_all(&rooms, &tab, 1));
	ft_putendl("FINISH");
	free_all(&rooms, &tab, 0);
	(void)argc;
	(void)argv;
	return (0);
}
