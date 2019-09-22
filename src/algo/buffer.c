/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:03:07 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/19 04:09:42 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		addchar_buff(int print, char char_to_append, t_lemin *l)
{
	if (print == 0)
		l->buff[l->index_buff] = char_to_append;
	else if (print == 1)
	{
		l->index_buff = 0;
		ft_putstr(l->buff);
		ft_bzero(l->buff, BUFF_SIZE);
		return (1);
	}
	l->index_buff++;
	if (l->index_buff == BUFF_SIZE - 1)
		addchar_buff(1, 0, l);
	return (1);
}

/*
** ==================== add_buff ====================
** append a char to buff, also check if need to print
*/

int		addnbr_buff(int nb_to_append, t_lemin *l)
{
	if (nb_to_append < 0)
	{
		addchar_buff(0, '-', l);
		nb_to_append = -nb_to_append;
	}
	if (nb_to_append >= 10)
	{
		addnbr_buff(nb_to_append / 10, l);
		addchar_buff(0, nb_to_append % 10 + '0', l);
	}
	else
		addchar_buff(0, nb_to_append % 10 + '0', l);
	return (1);
}

/*
** ==================== addnbr_buff ====================
** append an int to buff recursively calling itself and addchar_buff
*/

int		addstr_buff(char *str_to_append, t_lemin *l)
{
	int	i;

	i = 0;
	if (str_to_append)
	{
		while (str_to_append[i])
		{
			addchar_buff(0, str_to_append[i], l);
			i++;
		}
	}
	return (1);
}

/*
** ==================== addstr_buff ====================
** loop to add a string char by char in buff
*/
