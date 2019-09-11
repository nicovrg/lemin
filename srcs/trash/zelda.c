/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zelda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 02:56:23 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/10 02:56:44 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static	int		zelda(t_zelda **zelda, char *current_room_name, char *linked_room_name)
{
	t_zelda		*tmp_zelda;
	t_zelda		*new_zelda;
	
	tmp_zelda = *zelda;
	while (tmp_zelda && tmp_zelda->next)
		tmp_zelda = tmp_zelda->next;
	if (!(new_zelda = (t_zelda *)ft_memalloc(sizeof(t_zelda))))
		return (error_msg(ERR_MALLOC_11));
	if (!(new_zelda->coming = ft_strdup(current_room_name)))
		return (error_msg(ERR_MALLOC_12));
	if (!(new_zelda->going = ft_strdup(linked_room_name)))
		return (error_msg(ERR_MALLOC_13));
	new_zelda->lock = 0;
	new_zelda->next = NULL;
	if (!(*zelda))
		*zelda = new_zelda;
	else
		tmp_zelda->next = new_zelda;
	return (1);
}