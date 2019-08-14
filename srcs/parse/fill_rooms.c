/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/14 01:18:02 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		fill_rooms(t_room **rooms, t_norme *norme)
{
	t_room	*tmp;
	t_room	*new;

	tmp = (*rooms);
	while ((*rooms) && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->start = (norme->var == 1 || norme->var == 4) ? 1 : 0;
	new->end = (norme->var == 2 || norme->var == 3) ? 1 : 0;
	if (norme->var >= 3)
		norme->var = (norme->var == 3) ? 1 : 2;
	else
		norme->var = 0;
	if (!(new->name = ft_strsub(norme->line, 0, ft_strchr(norme->line, ' ') - norme->line)))
		return (0);
	new->next = NULL;
	new->links = NULL;
	if (!(*rooms))
		(*rooms) = new;
	else
		tmp->next = new;
	return (1);
}

/* ==================== fill_rooms ====================
** fill_rooms() append the room in norme->line at then end of t_room struct
** tmp if the last elem of the list
** new is the new elem we add to the list
** go to the end of the list and allocate a new t_room
** set t_room->start to 1 if it's the starting room 
** set t_room->end to 1 if it's the ending room 
** if var >= 3 it means we either had start follow by end
** at the next line or end follow by start so we put
** var at 1 if we expect the next line to be start, 
** var at 2 if we expect it to be end
** var at 0 if we dont have a start or end awaiting
** put the name of the room in t_room->name
** if it's the fist room, room = new
** if it's not the first room, room = tmp-next (to append the room after the last one)
*/
