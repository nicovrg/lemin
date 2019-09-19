/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_kchoz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 08:34:18 by nicolasv          #+#    #+#             */
/*   Updated: 2019/09/18 23:14:21 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		count_links(t_room **room)
{
	int		i;
	t_links	*tmp_link;

	i = 0;
	tmp_link = (*room)->links;
	while (tmp_link)
	{
		i++;
		tmp_link = tmp_link->next;
	}
	return (i);
}

/*
** ==================== count_links ====================
** count the number of links of a room
*/

int				nb_max_paths(t_lemin *l)
{
	int		nb_start_links;
	int		nb_end_links;
	t_room	*tmp;

	nb_end_links = 0;
	nb_start_links = 0;
	tmp = l->room;
	while (tmp && tmp->start != 1)
		tmp = tmp->next;
	nb_start_links = count_links(&tmp);
	tmp = l->room;
	while (tmp && tmp->end != 1)
		tmp = tmp->next;
	nb_end_links = count_links(&tmp);
	if (l->nb_ant <= nb_start_links && l->nb_ant <= nb_end_links)
		return (l->nb_ant);
	if (nb_start_links <= nb_end_links && nb_start_links <= l->nb_ant)
		return (nb_start_links);
	if (nb_end_links <= nb_start_links && nb_end_links <= l->nb_ant)
		return (nb_end_links);
	return (1);
}

/*
** ==================== nb_max_paths ====================
** return the minimum between nb_ant, nb_start_links, nb_end_links
** this number is the maximum of paths that we search
*/
