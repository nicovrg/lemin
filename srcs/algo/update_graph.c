/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:36:08 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/19 05:41:39 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	fill_path(t_lst_room **lst_rooms, t_links **links)
{
	t_links		*tmp_link;
	t_lst_room	*new_lst_room;
	t_lst_room	*tmp_lst_room;

	tmp_link = (*links);
	tmp_lst_room = (*lst_rooms);
	while (tmp_link && tmp_link->coming->end != 1)
	{
		new_lst_room = NULL;
		if (tmp_link->full == 1 && tmp_link->same_link->full != 1)
		{
			if (!(new_lst_room = (t_lst_room *)malloc(sizeof(t_lst_room))))
				return (error_msg(ERR_MALLOC_14));
			new_lst_room->next = NULL;
			new_lst_room->room = tmp_link->same_link->coming;
			tmp_lst_room->next = new_lst_room;
			tmp_lst_room = tmp_lst_room->next;
			tmp_link = tmp_link->same_link->coming->links;
		}
		else
			tmp_link = tmp_link->next;
	}
	return (1);
}

static int	update_paths(t_lemin *l, t_links **links, t_path **updated_paths)
{
	t_path *new_path;
	t_path *tmp_path;

	new_path = NULL;
	tmp_path = *updated_paths;
	while (tmp_path && tmp_path->next)
		tmp_path = tmp_path->next;
	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		return (error_msg(ERR_MALLOC_12));
	if (!(new_path->lst_rooms = (t_lst_room *)malloc(sizeof(t_lst_room))))
		return (error_msg(ERR_MALLOC_12));
	new_path->stop_ants = 0;
	new_path->lst_rooms->room = (*links)->coming;
	new_path->lst_rooms->next = NULL;
	new_path->next = NULL;
	if (!fill_path(&(new_path->lst_rooms), links))
		return (error_msg(ERR_MALLOC_13));
	new_path->length = count_lst_rooms(&(new_path->lst_rooms)) - 1;
	if (new_path->length < l->shortest_path || l->shortest_path == 0)
		l->shortest_path = new_path->length;
	if (!(*updated_paths))
		(*updated_paths) = new_path;
	else
		tmp_path->next = new_path;
	return (1);
}

/*
** ==================== update_path ====================
** allow to fill the t_path list
** and initialize l->shortest_path which correspond to
** the shortest path of this version of the graph
*/

static int	update_lemin_values(t_lemin *l, t_path **updated_paths,
int var, int ret)
{
	if (var == 1)
	{
		l->path = *updated_paths;
		l->temp_render = test_graph(l, updated_paths);
		l->final_short_path = l->shortest_path;
	}
	else if (var == 2)
	{
		free_paths(&(l->path));
		l->path = *updated_paths;
		l->temp_render = ret;
		l->final_short_path = l->shortest_path;
	}
	return (1);
}

static int	init_update_graph(t_lemin *l, t_path **updated_paths,
t_room **find_start, t_links **tmp_links)
{
	*updated_paths = NULL;
	*find_start = find_start_room(l);
	*tmp_links = (*find_start)->links;
	return (1);
}

int			update_graph(t_lemin *l)
{
	long	ret;
	t_path	*updated_paths;
	t_room	*find_start;
	t_links	*tmp_links;

	init_update_graph(l, &updated_paths, &find_start, &tmp_links);
	while (tmp_links)
	{
		if (tmp_links->full == 1)
			if (!update_paths(l, &(tmp_links), &updated_paths))
				return (error_msg(ERR_MALLOC_11));
		tmp_links = tmp_links->next;
	}
	if (!(l->path))
		update_lemin_values(l, &updated_paths, 1, 0);
	else
	{
		if (l->temp_render > (ret = test_graph(l, &updated_paths)))
			update_lemin_values(l, &updated_paths, 2, ret);
		else
			free_paths(&updated_paths);
	}
	l->shortest_path = 0;
	return (1);
}
