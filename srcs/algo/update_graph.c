/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:36:08 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/11 23:54:20 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		update_paths(t_lemin __unused *l, t_links __unused **links, t_path **updated_paths)
{
	t_path *new_path;
	t_path *tmp_path;

	new_path = NULL;
	tmp_path = *updated_paths;
    while (tmp_path && tmp_path->next)
		tmp_path = tmp_path->next;
	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (error_msg(ERR_MALLOC_12));
	new_path->next = NULL;
	if (!(*updated_paths))
		(*updated_paths) = new_path;
	else
		tmp_path->next = new_path;
	return (1);
}

/*
** ==================== update_path ====================
** 
*/

int				update_graph(t_lemin *l)
{
	t_path  *updated_paths;
	t_room  *find_start;

	updated_paths = NULL;
	find_start = find_start_room(l);
	while (find_start && find_start->links)
	{
		if (find_start->links->full == 1)
			if (!update_paths(l, &(find_start->links), &updated_paths))
				return (error_msg(ERR_MALLOC_11));
		find_start->links = find_start->links->next;
	}
	return (1);
}

/*
** ==================== update_graph ====================
** 
*/
