/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 02:39:11 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/20 02:45:45 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		fill_banned_rooms(t_ban **list, char *name)
{
	t_ban	*tmp;
	t_ban	*new;

	tmp = (*list);
	while ((*list) && tmp->next)
		tmp = tmp->next;
	if (!(new = (t_ban *)malloc(sizeof(t_ban))))
		return (0);
	if (!(new->name = ft_strdup(name)))
		return (0);
	new->next = NULL;
	if (!(*list))
		(*list) = new;
	else
		tmp->next = new;
	return (1);
}

/*
** ==================== fill__banned_rooms ====================
** this list is filled wiht the names of the rooms which we don't
** want to pass on because they are the end of a branch who don't
** have links with the end
*/

int		fill_rooms(t_room **rooms, t_norme *norme)
{
	t_room	*tmp;
	t_room	*new;
	
	tmp = (*rooms);
	while ((*rooms) && tmp->next && (ft_strncmp(tmp->name, norme->line,
	ft_strlen(norme->line) - ft_strlen(ft_strchr(norme->line, ' ')))
	|| ft_strlen(tmp->name) != ft_strlen(norme->line) - ft_strlen(ft_strchr(norme->line, ' '))))
		tmp = tmp->next;
	if (tmp && !ft_strncmp(tmp->name, norme->line,
	ft_strlen(norme->line) - ft_strlen(ft_strchr(norme->line, ' ')))
	&& ft_strlen(tmp->name) == ft_strlen(norme->line) - ft_strlen(ft_strchr(norme->line, ' ')))
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

/*
** ==================== fill_rooms ====================
** fill_rooms() append the room in norme->line at then end of t_room struct
** go to the end of the list
** allocate a new t_room
** set t_room->start to 1 if it's the starting room 
** set t_room->end to 1 if it's the ending room 
** 
*/
