/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 01:07:22 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/17 11:55:29 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

t_links	*add_room_in_path(t_links **buf, char *name)
{
	t_links	*tmp;
	t_links	*new;

	tmp = (*buf);
	while(*buf && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_links *)malloc(sizeof(t_links))))
		return (0);
	new->next = NULL;
	if (!(new->room = ft_strdup(name)))
		return (0);
	if (!(*buf))
		(*buf) = new;
	else
		tmp->next = new;
	return (new);
}

t_path	*init_paths(t_path **paths, int i, char *name)
{
	t_path	*tmp;
	t_path	*new;

	tmp = (*paths);
	while (*paths && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_path *)malloc(sizeof(t_path))))
		return (0);
	new->path = i;
	new->next = NULL;
	new->links = NULL;
	if (!(new->links = add_room_in_path(&(new->links), name)))
		return (0);
	if (!(*paths))
		(*paths) = new;
	else
		tmp->next = new;
	return (new);
}