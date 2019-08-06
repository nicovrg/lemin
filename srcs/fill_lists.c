/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/05 23:35:46 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		index_tubes(t_links **new, t_room **tmp)
{
	t_links	*buf;

	(*new)->next = NULL;
	if (!((*tmp)->links))
		(*tmp)->links = *new;
	else
	{
		buf = (*tmp)->links;
		while (buf->next)
			buf = buf->next;
		buf->next = *new;
	}
	return (1);
}

int		fill_tubes_with_room_bis(t_norme *norme, t_room **tmp,
		t_links **new, char *buf)
{
	if (!ft_strcmp((*tmp)->name, norme->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(buf, 0, ft_strlen(buf)
		- ft_strlen(norme->line) - 1)))
			return (0);
		index_tubes(new, tmp);
		norme->count++;
	}
	*tmp = (*tmp)->next;
	return (1);
}

int		fill_tubes_with_room(t_norme *norme, t_room **tmp, t_links **new,
		t_room **rooms)
{
	if (!ft_strncmp((*tmp)->name, norme->line,
	ft_strchr(norme->line, '-') - norme->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(norme->line,
		ft_strchr(norme->line, '-') - norme->line + 1, ft_strlen(norme->line)
		- ft_strlen(ft_strchr(norme->line, '-') + 1))))
			return (0);
		index_tubes(new, tmp);
		norme->line = ft_strchr(norme->line, '-') + 1;
		*tmp = (*rooms);
		norme->count++;
	}
	else
		(*tmp) = (*tmp)->next;
	return (1);
}

int		fill_tubes_list(t_room **rooms, char *line)
{
	t_room	*tmp;
	t_links	*new;
	t_norme	norme;
	char	*buf;

	tmp = (*rooms);
	norme.line = line;
	norme.count = 0;
	buf = line;
	while (tmp)
	{
		if (ft_strchr(norme.line, '-'))
		{
			if (!fill_tubes_with_room(&norme, &tmp, &new, rooms))
				return (0);
		}
		else
		{
			if (!fill_tubes_with_room_bis(&norme, &tmp, &new, buf))
				return (0);
		}
	}
	if (norme.count != 2)
		return (0);
	return (1);
}

int		fill_rooms_list(t_room **rooms, char *line, int *var)
{
	t_room	*tmp;
	t_room	*new;

	tmp = (*rooms);
	while ((*rooms) && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->start = (*var == 1 || *var == 4) ? 1 : 0;
	new->end = (*var == 2 || *var == 3) ? 1 : 0;
	if (*var >= 3)
		*var = (*var == 3) ? 1 : 2;
	else
		*var = 0;
	if (!(new->name = ft_strsub(line, 0, ft_strchr(line, ' ') - line)))
		return (1);
	new->next = NULL;
	new->links = NULL;
	if (!(*rooms))
		(*rooms) = new;
	else
		tmp->next = new;
	return (1);
}
