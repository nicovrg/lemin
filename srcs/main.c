/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/13 00:52:14 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

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

int		main(int argc, char **argv)
{
	int		nb_ant;
	t_room	*rooms;

	rooms = NULL;
	nb_ant = 0;
	if (!check_lines(&rooms, &nb_ant))
		return (free_all(&rooms, 1));
	if (!check_map_validity(&rooms))
		return (free_all(&rooms, 1));
	ft_putendl("FINISH");
	free_all(&rooms, 0);
	(void)argc;
	(void)argv;
	return (0);
}
