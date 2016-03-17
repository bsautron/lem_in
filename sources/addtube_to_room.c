#include <lem_in.h>

void	addtube_to_room(t_room *room, t_room *new)
{
	t_connection	*new_connection;

	new_connection = LIST_NEW(t_connection);
	new_connection->room = new;
	LIST_PUSH_BACK(&room->connection, new_connection);
}
