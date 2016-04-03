/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:48:00 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:48:23 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <errors.h>

static void	add_hl_room(t_anthill *house, t_room *room)
{
	t_room_list	*new_l;
	t_room_htab	*new_h;

	room->id = house->nb_rooms++;
	if (room->type == ROOM_START)
		house->start = room;
	else if (room->type == ROOM_END)
		house->end = room;
	new_l = LIST_NEW(t_room_list);
	new_l->room = room;
	new_h = LIST_NEW(t_room_htab);
	new_h->key = room->name;
	new_h->room = room;
	LIST_PUSH_FRONT(&house->rooms, new_l);
	HTAB_SET(&house->htab, new_h);
}

int			add_room(t_anthill *house, t_room *room, int explicit)
{
	if (room->type == ROOM_START && house->start != 0)
		no_more_start_room(explicit);
	else if (room->type == ROOM_END && house->end != 0)
		no_more_end_room(explicit);
	else
	{
		add_hl_room(house, room);
		return (1);
	}
	return (2);
}
