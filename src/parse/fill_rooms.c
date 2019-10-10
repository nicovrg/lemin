/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/10/09 10:13:20 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static int		init_rooms_values(t_room **new, t_parse *parse)
{
	(*new)->ant = 0;
	(*new)->start = (parse->var == 1 || parse->var == 4) ? 1 : 0;
	(*new)->end = (parse->var == 2 || parse->var == 3) ? 1 : 0;
	if (parse->var >= 3)
		parse->var = (parse->var == 3) ? 1 : 2;
	else
		parse->var = 0;
	(*new)->next = NULL;
	(*new)->links = NULL;
	return (1);
}

int				fill_rooms(t_lemin *l, t_parse *parse)
{
	t_room	*tmp;
	t_room	*new;

	tmp = l->room;
	while (l->room && tmp->next && (ft_strncmp(tmp->name, parse->line,
	ft_strlen(parse->line) - ft_strlen(ft_strchr(parse->line, ' ')))
	|| ft_strlen(tmp->name) != ft_strlen(parse->line)
	- ft_strlen(ft_strchr(parse->line, ' '))))
		tmp = tmp->next;
	if (tmp && !ft_strncmp(tmp->name, parse->line,
	ft_strlen(parse->line) - ft_strlen(ft_strchr(parse->line, ' ')))
	&& ft_strlen(tmp->name) == ft_strlen(parse->line)
	- ft_strlen(ft_strchr(parse->line, ' ')))
		return (0);
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (0);
		
	init_rooms_values(&new, parse);
	if (!(new->name = ft_strsub(parse->line, 0,
	ft_strchr(parse->line, ' ') - parse->line)))
		return (0);
	if (!l->room)
		l->room = new;
	else
		tmp->next = new;
	return (1);
}

/*
** ==================== fill_rooms ====================
** fill_rooms() append the room in parse->line at then end of t_room struct
** tmp if the last elem of the list
** new is the new elem we add to the list
** go to the end of the list and allocate a new t_room
** set t_room->start to 1 if it's the starting room
** set t_room->end to 1 if it's the ending room
** if var >= 3 it means we either had start follow by end
** at the next line or end follow by start so we put
** var at 1 if we expect the next line to be start,
** var at 2 if we expect it to be end
** var at 0 if we dont have a start or end awaiting
** put the name of the room in t_room->name
** if it's the fist room, room = new
** if it's not the first room, room = tmp-next
** (to append the room after the last one)
*/
