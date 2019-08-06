/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:17:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/05 23:46:08 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lemin.h"

int		dispatch_rooms_checking(t_room **rooms, char *line, int *status)
{
	if (!ft_strchr(line, ' ') && !ft_strchr(line, '-'))
		return (error_of_status(status));
	if (ft_strchr(line, '-'))
	{
		if (!check_if_tubes(rooms, line, status))
			return (error_of_status(status));
		return (0);
	}
	if (!check_coords_in_room(line))
		return (error_of_status(status));
	return (1);
}

int		check_with_status(t_room **rooms, char *line, int *status, int i)
{
	if (*status == 0)
	{
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
				return (error_of_status(status));
			i++;
		}
		*status = 1;
		return (0);
	}
	else if (*status == 1)
		if (!dispatch_rooms_checking(rooms, line, status))
			return (0);
	if (*status == 2)
	{
		if (!check_if_tubes(rooms, line, status))
			return (error_of_status(status));
		return (0);
	}
	return (1);
}

int		check_if_rooms(t_room **rooms, char *line, int *var, int *status)
{
	int		i;

	i = 0;
	if (line[0] == '#')
	{
		if (!ft_strcmp(line, "##start"))
			*var = (*var == 0) ? 1 : 3;
		else if (!ft_strcmp(line, "##end"))
			*var = (*var == 0) ? 2 : 4;
		return (0);
	}
	if (!check_with_status(rooms, line, status, i))
		return (0);
	return (1);
}

int		checklines(t_room **rooms, char ***tab)
{
	char	*line;
	int		i;
	int		var;
	int		status;

	line = NULL;
	i = 0;
	var = 0;
	status = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!(*tab = ft_realloctab(tab)))
			return (error_while_gnl(&line));
		if (!((*tab)[i] = ft_strdup(line)))
			return (error_while_gnl(&line));
		if (check_if_rooms(rooms, line, &var, &status))
			if (!fill_rooms_list(rooms, line, &var))
				return (error_while_gnl(&line));
		if (status == -1)
			return (error_with_status(&line, rooms));
		i++;
		ft_strdel(&line);
	}
	return (1);
}
