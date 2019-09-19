/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_links_to_full.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 00:24:01 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/19 04:34:04 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		put_links_to_full(t_queue **find_end)
{
	while ((*find_end) && (*find_end)->room->start != 1)
	{
		if ((*find_end) && (*find_end)->link)
			(*find_end)->link->full = 1;
		(*find_end) = (*find_end)->prev_link;
	}
	if ((*find_end) && (*find_end)->link)
		(*find_end)->link->full = 1;
	return (1);
}
