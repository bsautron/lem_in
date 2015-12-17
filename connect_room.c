#include <lem_in.h>

void	connect_room(t_room *room1, t_room *room2)
{
	addtube_to_room(room1, room2);
	addtube_to_room(room2, room1);
}
