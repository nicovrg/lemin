/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 00:17:22 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/05 01:42:54 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_map_validity(t_lemin *l)
{
	int		start;
	int		end;
	t_room	*tmp;

	tmp = l->room;
	start = 0;
	end = 0;
	while (tmp)
	{
		if (tmp->start == 1 && tmp->links)
			start++;
		if (tmp->end == 1 && tmp->links)
			end++;
		tmp = tmp->next;
	}
	if (start != 1 || end != 1)
		return (0);
	return (1);
}

/*
** ==================== check_map_validity ====================
** check if there is a start room and an end room
** also check if these rooms have links with other rooms
*/
