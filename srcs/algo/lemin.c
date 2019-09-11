/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/11 19:59:43 by nivergne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		count_links(t_room **room)
{
	int		i;
	t_links	*tmp_link;

	i = 0;
	tmp_link = (*room)->links;
	while (tmp_link)
	{
		i++;
		tmp_link = tmp_link->next;
	}
	return (i);
}

/*
** ==================== count_links ====================
** count the number of links of a room
*/

static int		nb_max_paths(t_lemin *l)
{
	int		nb_start_links;
	int		nb_end_links;
	t_room	*tmp;

	nb_end_links = 0;
	nb_start_links = 0;
	tmp = l->room;
	while (tmp && tmp->start != 1)
		tmp = tmp->next;
	nb_start_links = count_links(&tmp);
	tmp = l->room;
	while (tmp && tmp->end != 1)
		tmp = tmp->next;
	nb_end_links = count_links(&tmp);
	if (l->nb_ant <= nb_start_links && l->nb_ant <= nb_end_links)
		return (l->nb_ant);
	if (nb_start_links <= nb_end_links && nb_start_links <= l->nb_ant)
		return (nb_start_links);
	if (nb_end_links <= nb_start_links && nb_end_links <= l->nb_ant)
		return (nb_end_links);
	return (1);	
}

/*
** ==================== nb_max_paths ====================
** return the minimum between nb_ant, nb_start_links, nb_end_links
** this number is the maximum of paths that we search
*/

static int		init_lemin(t_lemin *l, t_queue **find_end, t_room **current_room, t_room **room_to_push)
{
	l->queue = NULL;
	*find_end = NULL;
	*current_room = NULL;
	*room_to_push = NULL;
	if (!(init_bfs(l, current_room)))
		return (error_msg(ERR_MALLOC_4));
	return (1);
}

/*
** ==================== init_lemin ====================
** init values declared in lemin function
*/

static	int		update_graph(t_lemin *l)
{
	static int i = 1;
	ft_printf("==================== CALL %d ====================\n", i++);

	t_room	*tmp_room;
	t_room	*tmp_room_wait_ptr;
	t_path	*tmp_path;
	char	*tmp_name;

	tmp_room = l->room;
	tmp_path = l->path;
	while (tmp_path && tmp_path->next)
		tmp_path = tmp_path->next;
	print_paths(&tmp_path);
	ft_printf(" = %s\n", tmp_path->lst_rooms->room);
	tmp_name = tmp_path->lst_rooms->room;
	tmp_path->lst_rooms = tmp_path->lst_rooms->next;
	ft_printf("tmp_name = %s\ttmp_path->lst_rooms->room = %s\n", tmp_name, tmp_path->lst_rooms->room);
	while (tmp_path && tmp_path->lst_rooms)
	{
		tmp_room_wait_ptr = find_room(l, tmp_path->lst_rooms->room);
		tmp_name = tmp_path->lst_rooms->room;
		while (tmp_room_wait_ptr && tmp_room_wait_ptr->end != 1)
		{
			// ft_printf("tmp_name = %s\ttmp_path->lst_rooms->room = %s\n", tmp_name, tmp_path->lst_rooms->room);
			tmp_room_wait_ptr = tmp_room_wait_ptr->next;
		}
		tmp_path->lst_rooms = tmp_path->lst_rooms->next;
	}
	// while (tmp_room && tmp_path && ft_strcmp(tmp_room->name, tmp_path->lst_rooms->room))
	// {
	// 	ft_printf("%s-%s\n", tmp_room->name, tmp_path->lst_rooms->room);
	// 	tmp_room = tmp_room->next;
	// }
	// tmp_links = tmp_path->lst_rooms->next;
	// tmp_path->lst_rooms = tmp_path->lst_rooms->next;
	// while (tmp_room && tmp_path && tmp_room->links && tmp_path->lst_rooms && ft_strcmp(tmp_room->links->room, tmp_path->lst_rooms->room))
	// 	tmp_room->links = tmp_room->links->next;
	return (1);
}

/*
** ==================== update_graph ====================
** iterate on all the paths until we are on the last one
** iterate in this last path starting from end, going to start
** move from the last room in the path to the previous room linked to it
** iterate through rooms untill we find room that match the 
*/

int				lemin(t_lemin *l)
{
	int		nb_path;
	t_queue	*find_end;
	t_queue	*queue_state;
	t_room	*room_to_push;
	t_room	*current_room;

	nb_path = 1;
	if (!(init_lemin(l, &find_end, &current_room, &room_to_push)))
		return (0);
	queue_state = l->queue;
	l->max_paths = nb_max_paths(l);
	while (l->max_paths && bfs(l, &queue_state, &current_room, &room_to_push) == 1)
	{
		find_end = (find_end) ? find_end->next : l->queue;
		while (find_end && find_end->room->end != 1)
			find_end = find_end->next;
		if (!find_end)
			return (1);
		if (!(fill_path(nb_path, &find_end, l)))
			return (error_msg(ERR_MALLOC_9));
		free_queue(&(l->queue));
		if (!(init_lemin(l, &find_end, &current_room, &room_to_push)))
			return (0);
		if (!update_graph(l))
			return (0);
		queue_state = l->queue;
		l->max_paths--;
		nb_path++;
	}
	return (1);
}

/*
** ==================== lemin ====================
** init a queue which contain start room at first
** queue_state is a pointer on the actual state of the queue ->
** we use it to avoid parsing all the links we already parse in the previous bfs
** while bfs return another path
** we need to go to end to fill the path in reverse cf doc fill_path ->
** so if we never found an end we start from the begining of the queue ->
** else we start from the previous end ->
** and we go to the next end in either case ->
** the we call fill_path and increment the number of path found
*/






















/*
** ==================== pseudo code ====================
** on veut parcourrir le graph
** trouver la salle du graph qui correspond au nom de la salle dans le lien du path
** mettre le forward entre cette salle et la salle suivante a 1
** continuer ce bordel
*/

/*
** ==================== reflexion ====================
** si on update le graph dans lequel on a déjà toutes les données et qu'on trouve que le chemin n'est en fait pas empruntable ...
** on va devoir revenir en arrière pour changer le chemin, c'est galère
** sinon on copie le graph et on remplace l'ancienne version si on a peu aller au bout de l'operation?
*/

// static	int		update_graph(t_room **room, t_path **paths)
// {
// 	static int i = 0;
// 	ft_printf("Call %d\n", i++);

// 	t_room	*tmp_room;
// 	t_path	*tmp_paths;
// 	t_links	*tmp_links;

// 	tmp_room = (*room);
// 	tmp_paths = (*paths);
// 	while (tmp_paths && tmp_paths->next)
// 		tmp_paths = tmp_paths->next;
// 	// print_paths(tmp_paths);
// 	// tmp_links = ()	

// 	while (tmp_room && tmp_paths && ft_strcmp(tmp_room->name, tmp_paths->lst_links->room))
// 		tmp_room = tmp_room->next;
// 	tmp_paths->lst_links = tmp_paths->lst_links->next;
// 	//segfault ici
// 	while (tmp_room && tmp_paths && ft_strcmp(tmp_room->links->room, tmp_paths->lst_links->room))
// 		tmp_room->links = tmp_room->links->next;
// 	// ft_printf("coucou\n");
// 	// ft_printf("room %s\n", tmp_room->links->room);
// 	// ft_printf("link %s\n", tmp_paths->lst_links->room);
// 	// tmp_room->links->forward == 1;
// 	return (1);
// }

// static	int		update_graph(t_room **room, t_path **paths)
// {
// 	t_room	*tmp_room;
// 	t_path	*tmp_paths;
// 	t_links	*tmp_links;

// 	tmp_room = (*room);
// 	tmp_paths = (*paths);
// 	while (tmp_paths && tmp_paths->next)
// 		tmp_paths = tmp_paths->next;
// 	while (tmp_room && tmp_paths && ft_strcmp(tmp_room->name, tmp_paths->lst_links->room))
// 		tmp_room = tmp_room->next;
// 	tmp_links = tmp_paths->lst_links->next;
// 	tmp_paths->lst_links = tmp_paths->lst_links->next;
// 	while (tmp_room && tmp_paths && ft_strcmp(tmp_room->links->room, tmp_paths->lst_links->room))
// 		tmp_room->links = tmp_room->links->next;
// 	return (1);
// }
