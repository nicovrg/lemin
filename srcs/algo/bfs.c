/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/22 04:16:20 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     init_bfs(t_room **room, t_queue **queue, t_room **current_room)
{
    (*current_room) = find_start_room(room);
    if (!init_queue(queue, current_room))
        return (error_msg(ERR_MALLOC_1));
    return (1);
}

/*
** ==================== init_bfs ====================
** init bfs
*/

int     bfs(t_room **room, t_queue **queue, t_room **current_room, t_room **room_to_push)
{
    t_links *tmp;
    
    tmp = NULL;
    while (*queue)
    {
        if (*current_room && (*current_room)->links)
            tmp = (*current_room)->links;
        while (tmp)
        {
            (*room_to_push) = find_room(room, tmp->room);
            tmp = tmp->next;
        }
        (*current_room) = pop_queue(queue);
    }
	free(*queue);
    return (1);
}

/*
** ==================== bfs ====================
** an implementation of breadth first search algorithm
** traverse the graph through breadth
*/
