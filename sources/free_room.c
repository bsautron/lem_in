#include <lem_in.h>

void	free_room(t_room *room)
{
	free(room->name);
	free(room);
}
