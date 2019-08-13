/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms_and_links.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 04:42:42 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/13 05:00:41 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

int		check_coords_in_room(char *line)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
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

/* ==================== check_coords_in_room ====================
** check_coords_in_room() check if coords are valids
*/

int		is_tubes(t_room **rooms, char *line, int *status)
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
	if (hyphen > 1 || !fill_tubes(rooms, line))
		return (0);
	return (1);
}

/* ==================== is_tubes ====================
** is_tubes() check if line represent a tube
** then call fill_tubes();
*/
