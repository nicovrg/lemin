/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:55:24 by nivergne          #+#    #+#             */
/*   Updated: 2019/09/02 22:01:20 by qgirard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

int		lemin(t_room **room, t_queue **queue, t_path **paths)
{
	int		nb_path;
	t_queue	*find_end;
	t_queue	*queue_state;
	t_room	*room_to_push;
	t_room	*current_room;

	nb_path = 0;
	find_end = NULL;
	current_room = NULL;
	room_to_push = NULL;
	if (!(init_bfs(room, queue, &current_room)))
		return (error_msg(ERR_MALLOC_4));
	queue_state = (*queue);
	while (bfs(room, &queue_state, &current_room, &room_to_push) == 1)
	{
		find_end = (find_end) ? find_end->next : *queue;
		while (find_end && find_end->room->end != 1)
			find_end = find_end->next;
		if (!(fill_path(nb_path, &find_end, paths)))
			return (error_msg(ERR_MALLOC_9));
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