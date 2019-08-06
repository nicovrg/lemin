/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/06 00:45:14 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		main(int argc, char **argv)
{
	t_room	*rooms;
	char	**tab;

	rooms = NULL;
	tab = NULL;
	(void)argc;
	(void)argv;
	if (!checklines(&rooms, &tab))
		return (free_lists(&rooms, &tab, 1));
	if (!check_map_validity(&rooms))
		return (free_lists(&rooms, &tab, 1));
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
	ft_putendl("FINISH");
	free_lists(&rooms, &tab, 0);
	return (0);
}
