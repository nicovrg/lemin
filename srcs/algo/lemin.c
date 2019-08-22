/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/22 06:26:37 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** ==================== pseudocode ====================
** while (bfs == true)
** update_grap
** check_graph output
** id new result is better, memorise result

** print result
*/

int		parse_queue(t_queue **current_queue, t_path **paths)
{
	t_queue	*tmp;

	tmp = (*current_queue);
	while (*current_queue && (*current_queue)->prev_room)
	{
		while (tmp && ft_strcmp((*current_queue)->prev_room, tmp->room->name))
			tmp = tmp->prev;
		if (tmp)
			if (!(add_room_in_path(&((*paths)->links), tmp->room->name)))
				return (0);
		*current_queue = tmp;
	}
	return (1);
}

int     lemin(t_room **room, t_queue **queue, t_path **paths)
{
    t_room  *current_room;
    t_room  *room_to_push;
	t_queue	*current_queue;
	t_queue	*tmp;
	int		nb_path;

    current_room = NULL;
    room_to_push = NULL;
	nb_path = 1;
    init_bfs(room, queue, &current_room);
	current_queue = (*queue);
    if (bfs(room, &current_queue, &current_room, &room_to_push) == 1)
    {
		tmp = (*queue);
		while (tmp && tmp->room->end != 1)
			tmp = tmp->next;
		if (tmp)
			init_paths(paths, nb_path, tmp->room->name);
		else
			return (0);
		while (tmp && tmp->prev_room)
			if (!(parse_queue(&tmp, paths)))
				return (0);
		nb_path++;
    }
	// while (*paths)
	// {
	// 	ft_printf("PATH = %d\n", (*paths)->path);
	// 	while (*paths && (*paths)->links)
	// 	{
	// 		ft_printf("%s\n", (*paths)->links->room);
	// 		(*paths)->links = (*paths)->links->next;
	// 	}
	// 	ft_putchar('\n');
	// 	*paths = (*paths)->next;
	// }
    return (1);
}
