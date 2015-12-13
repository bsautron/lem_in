#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <stdio.h>//

typedef struct		s_room
{
	char	*name;
	char	type;
	int		capacity;
	int		available;
	t_list	*list_tube;
}					t_room;

t_room		*create_room(char *name, char type);
void		free_room(t_room *room);

#endif
