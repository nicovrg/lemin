/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms_and_links.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 04:42:42 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/05 23:34:09 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		check_coords_in_room(char *line)
{
	int		space;
	int		i;

	space = 0;
	i = 0;
	if (!(line = ft_strchr(line, ' ') + 1))
		return (0);
	while (line && line[i])
	{
		while (line[i] && line[i] != ' ')
		{
			if (!ft_isdigit(line[i]))
				return (0);
			i++;
		}
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (space != 1)
		return (0);
	return (1);
}

int		check_if_tubes(t_room **rooms, char *line, int *status)
{
	int		i;
	int		hyphen;

	i = 0;
	hyphen = 0;
	*status = 2;
	if (ft_strchr(line, ' '))
		return (0);
	if (!ft_strchr(line, '-'))
		return (0);
	while (line && line[i])
	{
		if (line[i] == '-')
			hyphen++;
		i++;
	}
	if (hyphen > 1 || !fill_tubes_list(rooms, line))
		return (0);
	return (1);
}
