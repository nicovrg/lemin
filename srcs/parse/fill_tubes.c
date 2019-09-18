/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tubes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/18 22:56:51 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static int	free_link(t_links **new, t_parse *parse)
{
	ft_strdel(&((*new)->room));
	ft_memdel((void**)new);
	parse->ptr_link = NULL;
	return (1);
}

static int	index_tubes(t_links **new, t_room **tmp, t_parse *parse)
{
	t_links	*buf;

	(*new)->next = NULL;
	(*new)->coming = (*tmp);
	(*new)->full = 0;
	if (!((*tmp)->links))
		(*tmp)->links = *new;
	else
	{
		buf = (*tmp)->links;
		while (buf && buf->next)
		{
			if (!ft_strcmp(buf->room, (*new)->room))
				return (free_link(new, parse));
			buf = buf->next;
		}
		if (!ft_strcmp(buf->room, (*new)->room))
			return (free_link(new, parse));
		buf->next = *new;
	}
	return (1);
}

/*
** ==================== index_tubes ====================
** append tube on the room
** tmp is a copy of room
** (to keep the room address at the start of rooms)
*/

static int	fill_tubes_first_room(t_parse *parse, t_room **tmp,
t_links **new, t_lemin *l)
{
	if (!ft_strncmp((*tmp)->name, parse->line,
	ft_strchr(parse->line, '-') - parse->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(parse->line, ft_strchr(parse->line, '-')
		- parse->line + 1, ft_strlen(ft_strchr(parse->line, '-') + 1))))
			return (0);
		(*new)->same_link = NULL;
		parse->ptr_link = (*new);
		if (!index_tubes(new, tmp, parse))
			return (0);
		parse->line = ft_strchr(parse->line, '-') + 1;
		*tmp = l->room;
		parse->count++;
	}
	else
		(*tmp) = (*tmp)->next;
	return (1);
}

/*
** ==================== fill_tubes_first_room ====================
** send to index_tube the address of after the '-'
*/

static int	fill_tubes_last_room(t_parse *parse, t_room **tmp,
t_links **new, char *buf)
{
	if (!ft_strcmp((*tmp)->name, parse->line))
	{
		if (!((*new) = (t_links *)malloc(sizeof(t_links))))
			return (0);
		if (!((*new)->room = ft_strsub(buf, 0, ft_strlen(buf)
		- ft_strlen(parse->line) - 1)))
			return (0);
		if (parse->ptr_link)
			parse->ptr_link->same_link = (*new);
		(*new)->same_link = parse->ptr_link;
		if (!index_tubes(new, tmp, parse))
			return (0);
		parse->count++;
	}
	*tmp = (*tmp)->next;
	return (1);
}

/*
** ==================== fill_tubes_last_room ====================
** send to index_tube the address of before the '-'
*/

int			fill_tubes(t_lemin *l, char *line)
{
	char	*buf;
	t_room	*tmp;
	t_links	*new;
	t_parse	parse;

	buf = line;
	tmp = l->room;
	parse.line = line;
	parse.count = 0;
	parse.ptr_link = NULL;
	while (tmp)
	{
		new = NULL;
		if (ft_strchr(parse.line, '-'))
		{
			if (!fill_tubes_first_room(&parse, &tmp, &new, l))
				return (0);
		}
		else if (!fill_tubes_last_room(&parse, &tmp, &new, buf))
			return (0);
	}
	if (parse.count != 2)
		return (0);
	return (1);
}
