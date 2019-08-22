/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/08/22 02:03:52 by qgirard          ###   ########.fr       */
=======
/*   Updated: 2019/08/22 02:56:24 by nivergne         ###   ########.fr       */
>>>>>>> b80c5a994f36fca3df678a78bc7f88d92c07ba8c
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int     init_bfs(t_room **room, t_queue **queue, t_room **current_room)
{
<<<<<<< HEAD
    t_queue     *new;

    if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
        return (0);
    new->room = *room;
    new->room->discovered = 1;
    new->next = NULL;
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
    if (*queue)
        tmp_queue->next = new;
	else
		(*queue) = new;
=======
    (*current_room) = find_start_room(room);
    if (!init_queue(queue, current_room))
        return (error_msg(ERR_MALLOC_1));
>>>>>>> b80c5a994f36fca3df678a78bc7f88d92c07ba8c
    return (1);
}

/*
** ==================== init_bfs ====================
** init bfs
*/

int     bfs(t_room **room, t_queue **queue, t_room **current_room, t_room **room_to_push)
{
    t_links *tmp;
    
<<<<<<< HEAD
    tmp_queue = (*queue);
    if ((*queue) && (*queue)->next)
        (*queue) = (*queue)->next;
	else
	{
		// (*queue)->room = NULL;
		free(*queue);
		*queue = NULL;
	}
    if (*queue && tmp_queue)
	{
		// tmp_queue->room = NULL;
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
=======
    tmp = NULL;
>>>>>>> b80c5a994f36fca3df678a78bc7f88d92c07ba8c
    while (*queue)
    {
        if (*current_room && (*current_room)->links)
            tmp = (*current_room)->links;
        while (tmp)
        {
            (*room_to_push) = find_room(room, tmp->room);
            if ((*room_to_push)->discovered == 0 && !push_queue(queue, room_to_push))
                return (error_msg(ERR_MALLOC_2));
            tmp = tmp->next;
        }
        (*current_room) = pop_queue(queue);
    }
	// free(*queue);
    return (1);
}

/*
** ==================== bfs ====================
** an implementation of breadth first search algorithm
** traverse the graph through breadth
*/
