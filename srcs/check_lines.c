/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:17:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/06 04:26:59 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static int		dispatch_rooms_checking(t_room **rooms, char *line, int *status)
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

/*
** ==================== dispatch_rooms_checking ====================
** if there are no ' ' or '-' return error
** if there is '-' call check_if_tubes
**     if check_if_tubes() return 0 return error
**     else return 0
** if 
*/

static int		check_with_status(t_room **rooms, char *line, int *status, int i)
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

/*
** ==================== check_with_status ====================
** this function behave in different ways depending on the status value
** the first time it's call, status is equal to 0
** if status == 0, it check the first line only contain digit (ant number)
** then it increment the status value and return 0
** if status == 1, call dispatch_rooms_checking()
** if status == 2, if !check_if_tubes return an error, else return 0
** if status != 0/1/2 return 1
*/

static int		check_if_rooms(t_room **rooms, char *line, int *var, int *status)
{
	int	i;

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

/*
** ==================== check_if_rooms ====================
** je comprends pas pourquoi var peut prendre la valeur de 3
** end peut être avant start? sinon que faire si il y a deux starts / deux ends sur la même map?
*/


int		check_lines(t_room **rooms, char ***tab)
{
	int		i;
	int		var;
	int		status;
	char	*line;

	i = 0;
	var = 0;
	status = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(*tab = ft_realloctab(tab)))
			return (error_while_gnl(&line, ERR_PARSE_1));
		if (!((*tab)[i] = ft_strdup(line)))
			return (error_while_gnl(&line, ERR_PARSE_2));
		if (check_if_rooms(rooms, line, &var, &status))
			if (!fill_rooms_list(rooms, line, &var))
				return (error_while_gnl(&line, ERR_PARSE_3));
		if (status == -1)
			return (error_with_status(&line, rooms));
		i++;
		ft_strdel(&line);
	}
	return (1);
}

/*
** ==================== check_lines ====================
** read on the standard input
** then reallocate tab with (to add another cell) -- ft_realloctab()
** copy line in the tab last cell -- ft_strdup()
** check if line represent a room -- check_if_rooms()
** if line represent a room, append it to t_room structure -- fill_rooms_list()
** free line and return 1 (meaning no error code was return before and everything was ok)
*/
