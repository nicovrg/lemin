/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/13 23:15:21 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static int				index_tubes(t_links **new, t_room **tmp)
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

/* ==================== index_tubes ====================
** append tube on the room
** tmp is a copy of room 
** (to keep the room address at the start of rooms)
*/

static int				fill_tubes_first_room(t_norme *norme, t_room **tmp, t_links **new, t_room **rooms)
{
	if (!ft_strncmp((*tmp)->name, norme->line,
	ft_strchr(norme->line, '-') - norme->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(norme->line, ft_strchr(norme->line, '-') - norme->line + 1, ft_strlen(ft_strchr(norme->line, '-') + 1))))
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


/* ==================== fill_tubes_first_room ====================
** send to index_tube the address of after the '-'
*/

static int				fill_tubes_last_room(t_norme *norme, t_room **tmp, t_links **new, char *buf)
{
	if (!ft_strcmp((*tmp)->name, norme->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(buf, 0, ft_strlen(buf) - ft_strlen(norme->line) - 1)))
			return (0);
		index_tubes(new, tmp);
		norme->count++;
	}
	*tmp = (*tmp)->next;
	return (1);
}


/* ==================== fill_tubes_last_room ====================
** send to index_tube the address of before the '-'
*/

int						fill_tubes(t_room **rooms, char *line)
{
	char	*buf;
	t_room	*tmp;
	t_links	*new;
	t_norme	norme;

	tmp = (*rooms);
	norme.line = line;
	norme.count = 0;
	buf = line;
	while (tmp)
	{
		if (ft_strchr(norme.line, '-'))
		{
			if (!fill_tubes_first_room(&norme, &tmp, &new, rooms))
				return (0);
		}
		else if (!fill_tubes_last_room(&norme, &tmp, &new, buf))
			return (0);
	}
	if (norme.count != 2)
		return (0);
	return (1);
}


