/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/22 02:03:56 by nivergne         ###   ########.fr       */
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

int     lemin(t_room **room, t_queue **queue)
{
    t_room  *current_room;
    t_room  *room_to_push;

    current_room = NULL;
    room_to_push = NULL;
    init_bfs(room, queue, &current_room);
    if (bfs(room, queue, &current_room, &room_to_push) == 1)
    {
        return (1);
        //update_graph        
        //check_result
        //
    }
    return (1);
}
