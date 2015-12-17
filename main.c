#include <lem_in.h>

int		main(void)
{
	t_room	*start;
	t_room	*one;
	t_room	*two;
	t_room	*three;

	start = create_room(ft_strdup("Zero"), 1, 2, ROOM_START);
	three = create_room(ft_strdup("Three"), 5, 4, ROOM_NORMAL);
	two = create_room(ft_strdup("Two"), 5, 0, ROOM_NORMAL);
	one = create_room(ft_strdup("One"), 9, 2, ROOM_END);

	connect_room(start, two);
	show_room_prive(two);
	show_room_prive(start);
	return (0);
}
