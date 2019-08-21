/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_visited.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:41:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/20 01:28:27 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		room_is_banned(char *name, t_ban **list)
{
	t_ban	*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
** ==================== room_is_banned ====================
** check if the room is in the list of banned rooms
*/

int		room_is_passed(t_path **current, char *name)
{
	t_links	*tmp;

	tmp = (*current)->links;
	while (tmp)
	{
		if (tmp->room && !ft_strcmp(tmp->room, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
** ==================== room_is_passed ====================
** check if the room is already in the current path
*/