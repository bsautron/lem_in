#include <lem_in.h>

t_room	*create_room(char *name, int y, int x, char type)
{
	t_room		*new;

	new = LIST_NEW(t_room);
	ft_bzero(new, sizeof(t_room));
	new->connection = NULL;
	new->name = ft_strdup(name);
	new->type = type;
	new->y = y;
	new->x = x;
	new->available = 1;
	if (type == ROOM_START || type == ROOM_END)
		new->capacity = 1000; // define MAX or inf
	else
		new->capacity = 1;
	return (new);
}
