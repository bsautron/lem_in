#include <lem_in.h>

t_room	*create_room(char *name, int x, int y, char type)
{
	t_room		*new;

	new = LIST_NEW(t_room);
	new->name = name;
	new->type = type;
	new->y = y;
	new->x = x;
	if (type == ROOM_START || type == ROOM_END)
		new->capacity = 1000; // define MAX or inf
	else
		new->capacity = 1;
	return (new);
}
