/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dijsktra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:57:01 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 20:36:55 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_list_int	**init_tab_list_int(int len, int nb)
{
	t_list_int	**list;
	t_list_int	*elem;
	int			i;

	list = (t_list_int **)malloc(sizeof(t_list_int *) * (len + 1));
	list[len] = NULL;
	i = 0;
	while (i < len)
	{
		elem = LIST_NEW(t_list_int);
		elem->nb = nb;
		LIST_PUSH_FRONT(&list[i], elem);
		i++;
	}
	return (list);
}

static t_list_int	*init_list_int(int len)
{
	t_list_int	*list;
	t_list_int	*new;
	int			i;

	i = 0;
	list = NULL;
	while (i < len)
	{
		new = LIST_NEW(t_list_int);
		new->nb = i++;
		LIST_PUSH_FRONT(&list, new);
	}
	return (list);
}

static void			create_tab_room(t_anthill *house)
{
	int			n;
	t_room_list	*rooms;

	n = house->nb_rooms;
	house->dijkstra->tab_rooms = (t_room **)malloc(sizeof(t_room *) * (n + 1));
	house->dijkstra->tab_rooms[n] = NULL;
	rooms = house->rooms;
	while (rooms)
	{
		house->dijkstra->tab_rooms[rooms->room->id] = rooms->room;
		rooms = rooms->next;
	}
}

static void			create_adjacent_matrix(t_anthill *house)
{
	int		**matrix;
	int		n;
	int		i;

	n = house->nb_rooms;
	matrix = (int **)malloc(sizeof(int *) * (n + 1));
	matrix[n] = NULL;
	i = 0;
	while (i < n)
	{
		matrix[i] = (int *)malloc(sizeof(int) * n);
		ft_bzero(matrix[i], sizeof(int) * n);
		i++;
	}
	house->dijkstra->adjacent_matrix = matrix;
}

void				init_dijkstra(t_anthill *house)
{
	house->dijkstra = (t_dijkstra *)malloc(sizeof(t_dijkstra));
	create_tab_room(house);
	create_adjacent_matrix(house);
	house->dijkstra->dist = init_tab_list_int(house->nb_rooms, -1);
	house->dijkstra->pred = init_tab_list_int(house->nb_rooms, -1);
	house->dijkstra->already = NULL;
	house->dijkstra->rest = init_list_int(house->nb_rooms);
}
