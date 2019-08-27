/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grave_yard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 00:49:41 by nivergne          #+#    #+#             */
/*   Updated: 2019/08/28 00:50:33 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room*		pop_queue(t_queue **queue)
{
	t_queue *tmp_queue;
		
	tmp_queue = (*queue);
	if ((*queue) && (*queue)->next)
		(*queue) = (*queue)->next;
	else
	{
		(*queue)->room = NULL;
		free(*queue);
		*queue = NULL;
	}
	if (*queue && tmp_queue)
	{
		tmp_queue->room = NULL;
		free(tmp_queue);
		return ((*queue)->room);
	}
	return (NULL);
}

/*
** ==================== pop_queue ====================
** pop an element from the start of the queue
*/

