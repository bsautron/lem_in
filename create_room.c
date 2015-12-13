#include <lem_in.h>

t_room	*create_room(char *name, char type)
{
	t_room		*new;

	new = NULL;
	new = (t_room *)malloc(sizeof(t_room));
	new->name = name;
	new->type = type;
	new->available = 0;
	new->list_tube = NULL;
	if (type == 1 || type == 2)
		new->capacity = 1000; // define MAX or inf
	else
		new->capacity = 1;
	return (new);
}
