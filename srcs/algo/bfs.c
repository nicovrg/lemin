/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/22 01:01:01 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int         init_queue(t_queue **queue, t_room **room)
{
    t_queue     *new;

    if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
        return (0);
    new->room = *room;
    new->room->discovered = 1;
    new->next = NULL;
    if ((*queue))
        (*queue) = new;
    return (1);
}

/*
** ==================== init_queue ====================
** create and init a queue (list first in first out)
*/

int         push_queue(t_queue **queue, t_room **room)
{
    t_queue     *new;
    t_queue     *tmp_queue;


    tmp_queue = *queue;
    while ((*queue) && tmp_queue->next)
        tmp_queue = tmp_queue->next;
    if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
        return (0);
    new->room = (*room);
    new->room->discovered = 1;
    new->next = NULL;
    if (tmp_queue && tmp_queue->next)
        tmp_queue->next = new;
    ft_printf("coucou\n\n\n\n");
    return (1);
}

/*
** ==================== push_queue ====================
** add an element at the bottom of the queue
*/

t_room*    pop_queue(t_queue **queue)
{
    t_queue *tmp_queue;
    
    tmp_queue = (*queue);
    if ((*queue) && (*queue)->next)
        (*queue) = (*queue)->next;
	else
		*queue = NULL;
    if (*queue && tmp_queue)
	{
		free(tmp_queue);
    	return ((*queue)->room);
	}
    return (NULL);
}

/*
** ==================== pop_queue ====================
** pop an element from the start of the queue
*/

int         bfs(t_room **room, t_queue **queue)
{
    t_room  *current_room;
    t_room  *room_to_push;

    current_room = find_start_room(room);
    if (!init_queue(queue, &current_room))
        return (error_msg(ERR_MALLOC_1));
    while (*queue)
    {
        while (current_room && current_room->links)
        {
            room_to_push = find_room(room, current_room->links->room);
            if (room_to_push->discovered == 0 && !push_queue(queue, &room_to_push))
                return (error_msg(ERR_MALLOC_2));
            current_room->links = current_room->links->next;
        }
        current_room = pop_queue(queue);
    }
    return (1);
}

/*
** ==================== bfs ====================
** an implementation of breadth first search algorithm
** traverse the graph through breadth
*/