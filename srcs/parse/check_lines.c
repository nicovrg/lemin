/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:17:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/21 01:07:43 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static int		check_room_isvalid(t_room **rooms, char *line, int *status)
{
	if (!ft_strchr(line, ' ') && !ft_strchr(line, '-'))
		return (error_of_status(status));
	if (ft_strchr(line, '-'))
	{
		if (!is_tubes(rooms, line, status))
			return (error_of_status(status));
		return (0);
	}
	if (!check_coords_in_room(line))
		return (error_of_status(status));
	return (1);
}

/*
** ==================== check_room_isvalid ====================
** this function check if the room is valid and call the function
** to add the room to t_room structure
** it call is_tubes to get the first tubes without loosing line
** this call (is_tubes) should happen only once, 
*/

static int		check_status(t_room **rooms, t_norme *norme, int *status, int *nb_ant)
{
	if (*status == 0)
	{
		while (norme->line[norme->count])
		{
			if (!ft_isdigit(norme->line[norme->count]))
				return (error_of_status(status));
			norme->count = norme->count + 1;
		}
		if (norme->line)
			*nb_ant = ft_atoi(norme->line);
		*status = 1;
		return (0);
	}
	else if (*status == 1)
		return (check_room_isvalid(rooms, norme->line, status));
	else if (*status == 2)
	{
		if (!is_tubes(rooms, norme->line, status))
			return (error_of_status(status));
		return (0);
	}
	return (1);
}

/*
** ==================== check_status ====================
** this function behave in different ways depending on the status value
** it check if we are reading nb_ant, room or tubes
** the first time it's call, status is equal to 0
** if status == 0, it check the first line only contain digit (ant number)
** then it increment the status value and return 0
** if status == 1, call check_room_isvalid()
** if status == 2, call check_is_tube()
** return 1 if we append something on the list, 0 otherwise
*/

static int		is_room(t_room **rooms, t_norme *norme, int *status, int *nb_ant)
{
	norme->count = 0;
	if (norme->line[0] == '#')
	{
		if (!ft_strcmp(norme->line, "##start") && norme->start == 0)
		{
			norme->var = (norme->var == 0) ? 1 : 3;
			norme->start = 1;
		}
		else if (!ft_strcmp(norme->line, "##end") && norme->end == 0)
		{
			norme->var = (norme->var == 0) ? 2 : 4;
			norme->end = 1;
		}
		return (0);
	}
	if (!check_status(rooms, norme, status, nb_ant))
		return (0);
	return (1);
}

/*
** ==================== is_room ====================
** check if line start by a '#'
** if it does, check if it's the start or end room
** store we found a start/end in order to ignore possible doublons
** norme->var value will determine the order start and end are encounter
** norme->var = 0: no start, no end 
** norme->var = 1: start, no end
** norme->var = 2: end, no start
** norme->var = 3: end, start
** norme->var = 4: start, end
** then call check_status to know if we are reading nb_ant, room or tubes
*/

int				check_lines(t_room **rooms, int *nb_ant, char ***tab)
{
	int		i;
	int		status;
	char	*line;
	t_norme	norme;

	i = 0;
	norme.var = 0;
	norme.start = 0;
	norme.end = 0;
	status = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!(*tab = ft_realloctab(tab)))
			return (0);
		if (!((*tab)[i] = ft_strdup(line)))
			return (0);
		norme.line = line;
		if (is_room(rooms, &norme, &status, nb_ant))
			if (!fill_rooms(rooms, &norme))
				return (error_while_gnl(&line, ERR_PARSE_1));
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
** check if line represent a room -- is_room()
** if line represent a room, append it to t_room structure -- fill_rooms()
** note: is_room call check_status() which call is_tubes() which call fill_tubes()
** free line and return 1
** (meaning no error code was return before and everything was ok)
*/
