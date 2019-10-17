/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 05:13:42 by qgirard           #+#    #+#             */
/*   Updated: 2019/10/15 19:30:17 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		error_with_status(char **line, t_lemin *l)
{
	ft_strdel(line);
	if (!(check_map_validity(l)))
		return (0);
	return (1);
}

int		error_while_gnl(char **line, char *error_msg)
{
	ft_putendl(error_msg);
	ft_strdel(line);
	return (0);
}

int		error_of_status(int *status)
{
	*status = -1;
	return (0);
}

int		error_msg(char *error_msg)
{
	ft_putendl(error_msg);
	return (0);
}
