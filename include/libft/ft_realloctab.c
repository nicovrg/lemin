/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloctab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 00:38:28 by qgirard           #+#    #+#             */
/*   Updated: 2019/08/05 22:13:35 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloctab(char ***tab)
{
	char	**new;
	int		i;

	new = NULL;
	i = 0;
	while (*tab && (*tab)[i])
		i++;
	if (!(new = (char **)malloc(sizeof(char *) * (i + 2))))
		return (NULL);
	i = 0;
	while (*tab && (*tab)[i])
	{
		if (!(new[i] = ft_strdup((*tab)[i])))
			return (NULL);
		ft_strdel(&((*tab)[i]));
		i++;
	}
	new[i + 1] = NULL;
	if (*tab)
		free(*tab);
	return (new);
}
