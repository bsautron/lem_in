#include <lem_in.h>

t_room	*create_room(char *name, int y, int x, char type)
{
	t_room		*new;

	new = LIST_NEW(t_room);
	ft_bzero(new, sizeof(t_room));
	new->name = ft_strdup(name);
	new->type = type;
	new->y = y;
	new->x = x;
	return (new);
}
