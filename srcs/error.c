/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 05:13:42 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/06 04:06:45 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		error_with_status(char **line, t_room **rooms)
{
	ft_strdel(line);
	if (!(check_map_validity(rooms)))
		return (0);
	return (1);
}

int		error_while_gnl(char **line)
{
	ft_strdel(line);
	return (0);
}

int		error_of_status(int *status)
{
	*status = -1;
	return (0);
}
