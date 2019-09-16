/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasv <nicolasv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 02:17:19 by qgirard           #+#    #+#             */
/*   Updated: 2019/09/13 07:43:43 by nicolasv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

static int		check_room_isvalid(t_lemin *l, char *line, int *status)
{
	if (!ft_strchr(line, ' ') && !ft_strchr(line, '-'))
		return (error_of_status(status));
	if (ft_strchr(line, '-'))
	{
		if (!is_tubes(l, line, status))
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

static int		check_status(t_lemin *l, t_parse *parse, int *status)
{
	if (*status == 0)
	{
		while (parse->line[parse->count])
		{
			if (!ft_isdigit(parse->line[parse->count]) || ft_strlen(parse->line) >= 11)
				return (error_of_status(status));
			parse->count = parse->count + 1;
		}
		if (parse->line)
			l->nb_ant = ft_atol(parse->line);
		if (l->nb_ant > 2147483647)
			return (error_of_status(status));
		*status = 1;
		return (0);
	}
	else if (*status == 1)
		return (check_room_isvalid(l, parse->line, status));
	else if (*status == 2)
	{
		if (!is_tubes(l, parse->line, status))
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

static int		is_room(t_lemin *l, t_parse *parse, int *status)
{
	parse->count = 0;
	if (parse->line[0] == '#')
	{
		if (!ft_strcmp(parse->line, "##start") && parse->start == 0)
		{
			parse->var = (parse->var == 0) ? 1 : 3;
			parse->start = 1;
		}
		else if (!ft_strcmp(parse->line, "##end") && parse->end == 0)
		{
			parse->var = (parse->var == 0) ? 2 : 4;
			parse->end = 1;
		}
		return (0);
	}
	if (!check_status(l, parse, status))
		return (0);
	return (1);
}

/*
** ==================== is_room ====================
** check if line start by a '#'
** if it does, check if it's the start or end room
** store we found a start/end in order to ignore possible doublons
** parse->var value will determine the order start and end are encounter
** parse->var = 0: no start, no end 
** parse->var = 1: start, no end
** parse->var = 2: end, no start
** parse->var = 3: end, start
** parse->var = 4: start, end
** then call check_status to know if we are reading nb_ant, room or tubes
*/

int				check_lines(t_lemin *l)
{
	int		i;
	int		status;
	char	*line;
	t_parse	parse;

	i = 0;
	parse.var = 0;
	parse.start = 0;
	parse.end = 0;
	status = 0;
	line = NULL;
	while (get_next_line(0, &line) == 1)
	{
		if (!line[0])
			return (error_while_gnl(&line, ERR_PARSE_2));
		if (!(l->tab = ft_realloctab(&(l->tab))))
			return (0);
		if (!((l->tab)[i] = ft_strdup(line)))
			return (0);
		parse.line = line;
		if (is_room(l, &parse, &status))
			if (!fill_rooms(l, &parse))
				return (error_while_gnl(&line, ERR_PARSE_1));
		if (status == -1)
			return (error_with_status(&line, l));
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
