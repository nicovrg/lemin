/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graveyard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 01:03:23 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/06 01:03:24 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// int				del_room_in_path(t_path **current)
// {
// 	t_links	*tmp;
// 	t_links	*ptr;

// 	tmp = (*current)->links;
// 	ptr = (*current)->links;
// 	while ((*current)->links && tmp->next)
// 		tmp = tmp->next;
// 	while ((*current)->links && ptr->next && ptr->next != tmp)
// 		ptr = ptr->next;
// 	if (tmp && tmp->room)
// 		ft_strdel(&(tmp->room));
// 	ptr->next = NULL;
// 	if (tmp)
// 		free(tmp);
// 	return (1);
// }

// /*
// ** ==================== del_room_in_path ====================
// ** delete the last room on the current path
// */

// int				free_one_path(t_path **paths, t_path **current)
// {
// 	t_path	*tmp;
// 	t_links	*buf;
// 	t_links	*index;

// 	tmp = (*paths);
// 	while (*paths && *current && tmp->next && tmp->next != *current)
// 		tmp = tmp->next;
// 	if (*current)
// 	{
// 		buf = (*current)->links;
// 		while (buf)
// 		{
// 			index = buf;
// 			ft_strdel(&(index->room));
// 			buf = buf->next;
// 			free(index);
// 		}
// 		free(*current);
// 		tmp->next = NULL;
// 	}
// 	return (1);
// }
