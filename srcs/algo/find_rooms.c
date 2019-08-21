/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 04:20:19 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/21 04:21:31 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room*      find_start_room(t_room **room)
{
    t_room  *tmp_room;
    
    tmp_room = *room;
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

t_room*      find_room(t_room **room, char *name)
{
    t_room  *tmp_room;
    
    tmp_room = *room;
    while (tmp_room)
    {
        if (!ft_strcmp(tmp_room->name, name))
            return (tmp_room);
        tmp_room = tmp_room->next;
    }
    return (NULL);
}

/*
** ==================== find_start_room ====================
** return a copy of the pointer on the starting room
*/
