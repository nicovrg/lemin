/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 04:20:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/10/07 12:24:22 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*find_start_room(t_lemin *l)
{
	t_room	*tmp_room;

	tmp_room = l->room;
	while (tmp_room)
	{
		if (tmp_room->start == 1)
			return (tmp_room);
		tmp_room = tmp_room->next;
	}
	return (NULL);
}

/*
** ==================== find_start_room ====================
** return a copy of the pointer on the starting room
*/