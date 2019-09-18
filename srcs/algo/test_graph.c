/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 08:46:17 by nicolasv          #+#    #+#             */
/*   Updated: 2019/09/18 01:25:37 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_length_paths(t_lemin *l, t_path **updated_path)
{
	t_path	*tmp_path;

	tmp_path = (*updated_path);
	while (tmp_path)
	{
		if (l->stock > tmp_path->length || tmp_path->length == l->shortest_path)
			l->stock--;
		tmp_path = tmp_path->next;
	}
	return (1);
}

/*
** ==================== check_length_paths ====================
** 
*/

long	test_graph(t_lemin *l, t_path **updated_path)
{
	long	ret;

	ret = 0;
	l->stock = l->nb_ant;
	while (l->stock > 0)
	{
		check_length_paths(l, updated_path);
		ret++;
	}
	ret = ret + l->shortest_path - 1;
	return (ret);
}

/*
** ==================== test_graph ====================
** 
*/