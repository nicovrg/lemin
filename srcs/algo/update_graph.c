/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:36:08 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/12 03:01:18 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		fill_path(t_inpath **lst_rooms, t_links **links)
{
	t_links		*tmp_link;
	t_inpath	*new_inpath;
	t_inpath	*tmp_inpath;

	tmp_link = (*links);
	tmp_inpath = (*lst_rooms);
	while (tmp_link && tmp_link->coming->end != 1)
	{
		new_inpath = NULL;
		if (tmp_link->full == 1 && tmp_link->same_link->full != 1)
		{
			if (!(new_inpath = (t_inpath *)malloc(sizeof(t_inpath))))
				return (error_msg(ERR_MALLOC_14));
			new_inpath->next = NULL;
			new_inpath->room = tmp_link->same_link->coming;
			tmp_inpath->next = new_inpath;
			tmp_link = tmp_link->same_link->coming->links;
		}
		tmp_link = tmp_link->next;
	}
	return (1);
}

static	int		update_paths(t_links **links, t_path **updated_paths)
{
	t_path *new_path;
	t_path *tmp_path;

	new_path = NULL;
	tmp_path = *updated_paths;
    while (tmp_path && tmp_path->next)
		tmp_path = tmp_path->next;
	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (error_msg(ERR_MALLOC_12));
	if (!(new_path->lst_rooms = (t_inpath *)malloc(sizeof(t_inpath))))
		return (error_msg(ERR_MALLOC_12));
	new_path->lst_rooms->room = (*links)->coming;
	new_path->lst_rooms->next = NULL;
	new_path->next = NULL;
	if (!fill_path(&(new_path->lst_rooms), links))
		return (error_msg(ERR_MALLOC_13));
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
			if (!update_paths(&(find_start->links), &updated_paths))
				return (error_msg(ERR_MALLOC_11));
		find_start->links = find_start->links->next;
	}
	return (1);
}

/*
** ==================== update_graph ====================
** 
*/
