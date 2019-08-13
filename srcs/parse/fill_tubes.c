/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
<<<<<<< HEAD:srcs/parse/fill_lists.c
/*   Updated: 2019/08/13 22:49:46 by qgirard          ###   ########.fr       */
=======
/*   Updated: 2019/08/13 22:14:59 by nivergne         ###   ########.fr       */
>>>>>>> 86516d60d19a36b51d68a520d73652c17b53089e:srcs/parse/fill_tubes.c
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
<<<<<<< HEAD:srcs/parse/fill_lists.c
		if (!((*new)->room = ft_strsub(norme->line, ft_strchr(norme->line, '-')
		- norme->line + 1, ft_strlen(ft_strchr(norme->line, '-') + 1))))
=======
		if (!((*new)->room = ft_strsub(buf, 0,
		ft_strlen(buf) - ft_strlen(norme->line) - 1)))
>>>>>>> 86516d60d19a36b51d68a520d73652c17b53089e:srcs/parse/fill_tubes.c
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


<<<<<<< HEAD:srcs/parse/fill_lists.c
	tmp = (*rooms);
	while ((*rooms) && tmp->next && ft_strncmp(tmp->name, norme->line,
	ft_strlen(norme->line) - ft_strlen(ft_strchr(norme->line, ' '))))
		tmp = tmp->next;
	if (tmp && !ft_strncmp(tmp->name, norme->line,
	ft_strlen(norme->line) - ft_strlen(ft_strchr(norme->line, ' '))))
		return (0);
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
	new->start = (norme->var == 1 || norme->var == 4) ? 1 : 0;
	new->end = (norme->var == 2 || norme->var == 3) ? 1 : 0;
	if (norme->var >= 3)
		norme->var = (norme->var == 3) ? 1 : 2;
	else
		norme->var = 0;
	if (!(new->name = ft_strsub(norme->line, 0,
	ft_strchr(norme->line, ' ') - norme->line)))
		return (0);
	new->next = NULL;
	new->links = NULL;
	if (!(*rooms))
		(*rooms) = new;
	else
		tmp->next = new;
	return (1);
}
=======
/* ==================== fill_tubes ====================
** call the functions that add links to rooms
*/
>>>>>>> 86516d60d19a36b51d68a520d73652c17b53089e:srcs/parse/fill_tubes.c
