#include <lem_in.h>
#include <parser.h>

int		main(int argc, char const **argv)
{
	t_args			args;
	t_anthill		house;

	init_options(&args, "lem_in");
	add_desc(&args, "Un programme qui fait ca.");
	add_desc(&args, "Il prend en param des truk comme ca.");
	add_desc(&args, "Le but est de fait ca.");
	add_option(&args, "-s", "--show", "Show anthill");
	add_option(&args, "-S", "--shosdfw", "Show anthill");
	if (!parse_options(&args, argc, argv))
		return (0);

	char	*line;
	t_parser	parse;

	house = init_anthill();
	parse = create_parser(&house);

	line = NULL;
	while (get_next_line(0, &line) > 0)
		parser(&parse, line);

	// add_room(&house, create_room("r0", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r1", 0, 0, ROOM_START));
	// add_room(&house, create_room("r2", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r3", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r4", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r5", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r6", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r7", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r8", 0, 0, ROOM_END));
	//
	// add_room(&house, create_room("r9", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r10", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r11", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r12", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r13", 0, 0, ROOM_NORMAL));
	// add_room(&house, create_room("r14", 0, 0, ROOM_NORMAL));

	

	// connect_room(&house, "r1", "r9");
	// connect_room(&house, "r9", "r10");
	// connect_room(&house, "r10", "r11");
	// connect_room(&house, "r11", "r12");
	// connect_room(&house, "r12", "r13");
	// connect_room(&house, "r13", "r14");
	// connect_room(&house, "r14", "r8");
	//
	// connect_room(&house, "r1", "r2");
	// connect_room(&house, "r1", "r4");
	// connect_room(&house, "r2", "r3");
	// connect_room(&house, "r2", "r7");
	// connect_room(&house, "r4", "r3");
	// connect_room(&house, "r3", "r7");
	// connect_room(&house, "r3", "r5");
	// connect_room(&house, "r5", "r6");
	// connect_room(&house, "r6", "r8");
	// connect_room(&house, "r7", "r8");
	print_matrix(house);
	// add_ant(&house, "r1");
	// add_ant(&house, "r1");
	if (option_is_set(args, "-s--show"))
		show_anthill(house);

	dijkstra_it(&house);

	int					i_r;
	int					i;

	i_r = 0;
	while (house.roads->road[i_r])
	{
		i = 0;
		while (i < house.roads->nb_steps[i_r])
		{
			printf("%d ", house.roads->tab_roads[i_r][i]);
			i++;
		}
		printf("%s\n", "");
		i_r++;
	}
	move_ants(&house);
	return (0);
}
