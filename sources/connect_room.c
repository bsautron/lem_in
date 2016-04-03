/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:51:12 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 20:30:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		put_one(t_dijkstra *dijkstra, int id1, int id2)
{
	dijkstra->adjacent_matrix[id1][id2] = 1;
	dijkstra->adjacent_matrix[id2][id1] = 1;
}

int				connect_room(t_anthill *house, char *room1, char *room2, int e)
{
	t_room_htab		*hroom1;
	t_room_htab		*hroom2;

	hroom1 = HTAB_GET(house->htab, t_room_htab, room1);
	hroom2 = HTAB_GET(house->htab, t_room_htab, room2);
	if (!hroom1 && e)
	{
		ft_putstr_fd("Room [", 2);
		ft_putstr_fd(room1, 2);
		ft_putendl_fd("] doesn't exit", 2);
	}
	if (!hroom2 && e)
	{
		ft_putstr_fd("Room [", 2);
		ft_putstr_fd(room2, 2);
		ft_putendl_fd("] doesn't exit", 2);
	}
	if (hroom2 && hroom1)
	{
		put_one(house->dijkstra, hroom1->room->id, hroom2->room->id);
		return (1);
	}
	return (0);
}
