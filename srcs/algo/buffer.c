/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:03:07 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/18 23:54:30 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		addchar_buff(int print, int index, char *buff, char char_to_append)
{
	if (print == 0)
		buff[index] = char_to_append;
	else if (print == 1)
	{
		index = 0;
		ft_putstr(buff);
		ft_bzero(buff, BUFF_SIZE);
		return (1);
	}
	index++;
	if (index == BUFF_SIZE - 1)
		addchar_buff(1, index, buff, 0);
	return (1);
}

/*
** ==================== add_buff ====================
** append a char to buff, also check if need to print 
*/
int		addnbr_buff(int index, char *buff, int nb_to_append)
{
	if (nb_to_append < 0)
	{
		addchar_buff(0, index, buff, '-');
		nb_to_append = -nb_to_append;
	}
	if (nb_to_append >= 10)
	{
		addnbr_buff(index, buff, nb_to_append / 10);
		addchar_buff(0, index, buff, nb_to_append % 10 + '0');
	}
	else
		addchar_buff(0, index, buff, nb_to_append % 10 + '0');
	return (1);
}

/*
** ==================== addnbr_buff ====================
** append an int to buff recursively calling itself and addchar_buff
*/

int		addstr_buff(int index, char *buff, char *str_to_append)
{
	int	i;

	i = 0;
	if (str_to_append)
	{
		while (str_to_append[i])
		{
			addchar_buff(0, index, buff, str_to_append[i]);
			i++;
		}
	}
	return (1);
}

/*
** ==================== addstr_buff ====================
** loop to add a string char by char in buff
*/