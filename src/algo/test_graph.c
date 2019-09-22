/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 08:46:17 by nicolasv          #+#    #+#             */
/*   Updated: 2019/09/19 04:52:56 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_length_paths(t_lemin *l, t_path **updated_path)
{
	t_path	*tmp_path;

	tmp_path = (*updated_path);
	while (tmp_path)
	{
		if (l->stock > tmp_path->stop_ants)
			l->stock--;
		tmp_path = tmp_path->next;
	}
	return (1);
}

/*
** ==================== check_length_paths ====================
** check length paths and decrement number of ants when a path
** is loanable when compare number of ants and stop_ants
*/

int		put_stop_ants_in_paths(t_lemin *l, t_path **updated_path)
{
	t_path	*tmp_path;
	t_path	*parse_paths;

	tmp_path = *updated_path;
	while (tmp_path)
	{
		parse_paths = *updated_path;
		while (parse_paths && tmp_path->length > l->shortest_path)
		{
			if (parse_paths != tmp_path
			&& tmp_path->length > parse_paths->length)
				tmp_path->stop_ants = tmp_path->stop_ants
				+ (tmp_path->length - parse_paths->length);
			parse_paths = parse_paths->next;
		}
		tmp_path = tmp_path->next;
	}
	return (1);
}

/*
** ==================== put_stop_ants_in_path ====================
** we put a variable stop_ants in each path
** stop_ants = sum of differences between length of current path
** and lengths of shorter paths
** when the number of ants is less bigger than the stop_ants value
** the path is no longer loanable by ants
*/

long	test_graph(t_lemin *l, t_path **updated_path)
{
	long	ret;

	ret = 0;
	l->stock = l->nb_ant;
	put_stop_ants_in_paths(l, updated_path);
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
** initialize l->stock to number of ants
** this function test a state of the graph to know
** the number of lines that would print this version of the graph
*/
