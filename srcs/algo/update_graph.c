/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:36:08 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/11 01:43:04 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		update_graph(t_lemin *l)
{
	t_path	*updated_paths;
	t_room	*find_end;

	updated_paths = NULL;
	find_end = l->path->ptr_room;
	while (find_end && find_end->links)
	{
		find_end->links = find_end->links->next;
	}
	return (1);
}