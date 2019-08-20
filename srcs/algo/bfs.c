/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 01:19:51 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/20 05:02:24 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

typedef struct      s_queue
{
    t_room          *room;
    struct s_queue  *next;
}                   t_queue;

int         init_queue(t_queue **queue, t_room **room)
{
    (*queue)->room = *room;
    (*queue)->next = NULL;
    return (1);
}

int         push_queue(t_queue **queue, t_room **room)
{
    while ((*queue)->next)
        (*queue) = (*queue)->next;
    (*queue)->next->room = *room;
    return (1);
}

t_room*    pop_queue(t_queue **queue)
{
    return ((*queue)->room);
}

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

int         bfs(t_room **room)
{
    t_queue *queue;
    t_room  *bfs_room;

    bfs_room = find_start_room(room);
    init_queue(&queue, &bfs_room);
    return (1);
}