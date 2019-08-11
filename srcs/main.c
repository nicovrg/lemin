/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 01:40:55 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/11 18:54:18 by nivergne         ###   ########.fr       */
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
		return (free_lists(&rooms, &tab, 1));
	if (!check_map_validity(&rooms))
		return (free_lists(&rooms, &tab, 1));
	ft_putendl("FINISH");
	free_lists(&rooms, &tab, 0);
	(void)argc;
	(void)argv;
	return (0);
}

//refaire la norme dans la libft (ft_realloc tab)
//realloc tab meilleure solution? (opti futur du temps sur les grosses maps, faire 10 000 mallocs peut être pas fou - après peut être osef, juste opti l'algo en vitesse)
//realloc tab va réallouer le même tableau avec une case en plus en recopiant tout si j'ai bien suivit?
//utiliser une liste plus approprié?
//checklines => check_lines
//pourquoi t_room *room? ça fonctionne pas sans le pointeur?
//