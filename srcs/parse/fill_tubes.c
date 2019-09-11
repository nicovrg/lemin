/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/11 20:28:28 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static int				free_link(t_links **new, t_norme *norme)
{
	ft_strdel(&((*new)->room));
	ft_memdel((void**)new);
	norme->ptr_link = NULL;
	// free(*new);
	return (1);
}

static int				index_tubes(t_links **new, t_room **tmp, t_norme *norme)
{
	t_links	*buf;

	(*new)->next = NULL;
	(*new)->ptr_room = NULL;
	(*new)->coming = (*tmp);
	// if (!((*new)->coming = ft_strdup((*tmp)->name)))
	// 	return (0);
	(*new)->ant = 0;
	(*new)->full = 0;
	if (!((*tmp)->links))
		(*tmp)->links = *new;
	else
	{
		buf = (*tmp)->links;
		while (buf && buf->next)
		{
			if (!ft_strcmp(buf->room, (*new)->room))
				return (free_link(new, norme));
			buf = buf->next;
		}
		if (!ft_strcmp(buf->room, (*new)->room))
			return (free_link(new, norme));
		buf->next = *new;
	}
	return (1);
}

/* ==================== index_tubes ====================
** append tube on the room
** tmp is a copy of room 
** (to keep the room address at the start of rooms)
*/

static int				fill_tubes_first_room(t_norme *norme, t_room **tmp, t_links **new, t_lemin *l)
{
	// norme->ptr_link = l->room;
	// while (norme->ptr_link && ft_strcmp(norme->ptr_link->name, ft_strchr(norme->line, '-') + 1))
	// 	norme->ptr_link = norme->ptr_link->next;
	if (!ft_strncmp((*tmp)->name, norme->line, ft_strchr(norme->line, '-') - norme->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(norme->line, ft_strchr(norme->line, '-') - norme->line + 1, ft_strlen(ft_strchr(norme->line, '-') + 1))))
			return (0);
		(*new)->same_link = NULL;
		norme->ptr_link = (*new);
		if (!index_tubes(new, tmp, norme))
			return (0);
		// (*new)->ptr_room = norme->ptr_link;
		// norme->ptr_link = l->room;
		norme->line = ft_strchr(norme->line, '-') + 1;
		*tmp = l->room;
		norme->count++;
	}
	else
		(*tmp) = (*tmp)->next;
	return (1);
}


/* ==================== fill_tubes_first_room ====================
** send to index_tube the address of after the '-'
*/

static int				fill_tubes_last_room(t_norme *norme, t_room **tmp, t_links **new, char *buf)
{
	// while (norme->ptr_link
	// && ft_strncmp(norme->ptr_link->name, buf, ft_strlen(buf) - ft_strlen(norme->line) - 1))
	// 	norme->ptr_link = norme->ptr_link->next;
	if (!ft_strcmp((*tmp)->name, norme->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(norme->line) - 1)))
			return (0);
		if (norme->ptr_link)
			norme->ptr_link->same_link = (*new);
		(*new)->same_link = norme->ptr_link;
		if (!index_tubes(new, tmp, norme))
			return (0);
		// (*new)->ptr_room = norme->ptr_link;
		norme->count++;
	}
	*tmp = (*tmp)->next;
	return (1);
}


/* ==================== fill_tubes_last_room ====================
** send to index_tube the address of before the '-'
*/

int						fill_tubes(t_lemin *l, char *line)
{
	char	*buf;
	t_room	*tmp;
	t_links	*new;
	t_norme	norme;

	buf = line;
	tmp = l->room;
	norme.line = line;
	norme.count = 0;
	norme.ptr_link = NULL;
	while (tmp)
	{
		new = NULL;
		if (ft_strchr(norme.line, '-'))
		{
			if (!fill_tubes_first_room(&norme, &tmp, &new, l))
				return (0);
		}
		else if (!fill_tubes_last_room(&norme, &tmp, &new, buf))
			return (0);
	}
	if (norme.count != 2)
		return (0);
	return (1);
}
