#include <lem_in.h>

int		main(int argc, char const **argv)
{
	t_args			args;
	t_anthill		house;

	init_options(&args);
	add_option(&args, "-s", "--show", "Show anthill");
	add_option(&args, "-h", "--help", "Display help");
	parse_options(&args, argc, argv);
	/* --- */
	house = init_anthill();
	add_room(&house, create_room("Zero", 1, 2, ROOM_START));
	add_room(&house, create_room("Three", 5, 4, ROOM_NORMAL));
	add_room(&house, create_room("Two", 5, 0, ROOM_NORMAL));
	add_room(&house, create_room("One", 9, 2, ROOM_END));
	connect_room(house, "One", "Two");
	connect_room(house, "One", "Three");
	connect_room(house, "One", "Zero");
	connect_room(house, "Zero", "Three");
	add_ant(&house, "Zero");
	add_ant(&house, "Zero");
	add_ant(&house, "Zero");
	add_ant(&house, "Zero");
	if (option_is_set(args, "-s--show"))
		show_anthill(house);
	find_all_road(&house);
	return (0);
}
