#include <lem_in.h>

int		main(void)
{
	t_anthill		house;

	house = init_anthill();
	add_room(&house, create_room("Zero", 1, 2, ROOM_START));
	add_room(&house, create_room("Three", 5, 4, ROOM_NORMAL));
	add_room(&house, create_room("Two", 5, 0, ROOM_NORMAL));
	add_room(&house, create_room("One", 9, 2, ROOM_END));
	connect_room(house, "One", "Two");
	connect_room(house, "One", "Three");
	connect_room(house, "One", "Zero");
	connect_room(house, "Zero", "Three");

	show_anthill(house);
	return (0);
}
