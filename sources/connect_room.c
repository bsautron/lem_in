#include <lem_in.h>

void	connect_room(t_anthill house, char *room1, char *room2)
{
	t_room_htab		*hroom1;
	t_room_htab		*hroom2;

	hroom1 = HTAB_GET(house.htab, t_room_htab, room1);
	hroom2 = HTAB_GET(house.htab, t_room_htab, room2);
	addtube_to_room(hroom1->room, hroom2->room);
	addtube_to_room(hroom2->room, hroom1->room);
}
