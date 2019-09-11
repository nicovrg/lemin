/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:13:55 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/11 20:13:56 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// static	int		update_graph(t_lemin *l)
// {
// 	static int i = 1;
// 	ft_printf("==================== CALL %d ====================\n", i++);

// 	t_room	*tmp_room;
// 	t_room	*tmp_room_wait_ptr;
// 	t_path	*tmp_path;
// 	char	*tmp_name;

// 	tmp_room = l->room;
// 	tmp_path = l->path;
// 	while (tmp_path && tmp_path->next)
// 		tmp_path = tmp_path->next;
// 	print_paths(&tmp_path);
// 	ft_printf(" = %s\n", tmp_path->lst_rooms->room);
// 	tmp_name = tmp_path->lst_rooms->room;
// 	tmp_path->lst_rooms = tmp_path->lst_rooms->next;
// 	ft_printf("tmp_name = %s\ttmp_path->lst_rooms->room = %s\n", tmp_name, tmp_path->lst_rooms->room);
// 	while (tmp_path && tmp_path->lst_rooms)
// 	{
// 		tmp_room_wait_ptr = find_room(l, tmp_path->lst_rooms->room);
// 		tmp_name = tmp_path->lst_rooms->room;
// 		while (tmp_room_wait_ptr && tmp_room_wait_ptr->end != 1)
// 		{
// 			// ft_printf("tmp_name = %s\ttmp_path->lst_rooms->room = %s\n", tmp_name, tmp_path->lst_rooms->room);
// 			tmp_room_wait_ptr = tmp_room_wait_ptr->next;
// 		}
// 		tmp_path->lst_rooms = tmp_path->lst_rooms->next;
// 	}
// 	// while (tmp_room && tmp_path && ft_strcmp(tmp_room->name, tmp_path->lst_rooms->room))
// 	// {
// 	// 	ft_printf("%s-%s\n", tmp_room->name, tmp_path->lst_rooms->room);
// 	// 	tmp_room = tmp_room->next;
// 	// }
// 	// tmp_links = tmp_path->lst_rooms->next;
// 	// tmp_path->lst_rooms = tmp_path->lst_rooms->next;
// 	// while (tmp_room && tmp_path && tmp_room->links && tmp_path->lst_rooms && ft_strcmp(tmp_room->links->room, tmp_path->lst_rooms->room))
// 	// 	tmp_room->links = tmp_room->links->next;
// 	return (1);
// }

/*
** ==================== update_graph ====================
** iterate on all the paths until we are on the last one
** iterate in this last path starting from end, going to start
** move from the last room in the path to the previous room linked to it
** iterate through rooms untill we find room that match the 
*/
