/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/21 01:29:06 by nivergne         ###   ########.fr       */
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

t_room**      find_room(t_room **room, char *name)
{
    t_room  *tmp_room;
    
    tmp_room = *room;
    while (tmp_room)
    {
        if (!ft_strcmp(tmp_room->name, name))
            return (&tmp_room);
        tmp_room = tmp_room->next;
    }
    return (NULL);
}

/*
** ==================== find_start_room ====================
** return a copy of the pointer on the starting room
*/

typedef struct      s_queue
{
    t_room          *room;
    struct s_queue  *next;
}                   t_queue;

int         init_queue(t_queue **queue, t_room **room)
{
    t_queue     *new;

    if (!(new = (t_queue *)ft_memalloc(sizeof(t_queue))))
        return (0);
    new->room = *room;
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
    new->next = NULL;
    tmp_queue->next = new;
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
    if (!(*queue) || (*queue)->next)
        return (NULL);
    (*queue) = (*queue)->next;
    free(&tmp_queue);
    return ((*queue));
}

/*
** ==================== pop_queue ====================
** pop an element from the start of the queue
*/

int         bfs(t_room **room)
{
    t_queue *queue;
    t_room  *current_room;

    queue = NULL;
    current_room = find_start_room(room);
    if (!init_queue(&queue, &current_room))
        return (error_msg(ERR_MALLOC_1));
    while (!queue)
    {
        while (current_room->links)
        {
            if (!push_queue(&queue, find_room(room, current_room->links->room)))
                return (error_msg(ERR_MALLOC_2));
            current_room->links = current_room->links->next;
        }
        current_room = pop_queue(&queue);
    }
    return (1);
}

/*
** ==================== bfs ====================
** an implementation of breadth first search algorithm
** traverse the graph through breadth
*/