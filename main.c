#include <lem_in.h>
#include <parser.h>
#include <errors.h>

static void 	show_road(t_anthill house)
{
	int		i_room;
	t_list_int	*tmp;

	i_room = 0;
	ft_putendl("ROADS:");
	while (i_room < house.roads->nb_roads)
	{
		ft_putstr("\t");
		ft_putnbr(i_room + 1);
		ft_putstr(" (");
		ft_putnbr(house.roads->nb_ants[i_room]);
		ft_putstr(" ants, ");
		ft_putnbr(house.roads->nb_steps[i_room]);
		ft_putstr(" steps): ");
		tmp = house.roads->road[i_room];
		while (tmp)
		{
			ft_putstr(house.dijkstra->tab_rooms[tmp->nb]->name);
			ft_putstr((tmp->next) ? " - " : "");
			tmp = tmp->next;
		}
		ft_putchar('\n');
		i_room++;
	}
	ft_putchar('\n');
}

static void 	show_nb_step(int nb)
{
	ft_putstr("\nNUMBER OF STEPS: ");
	ft_putnbr(nb);
	ft_putchar('\n');
}

static void 	prepare_options(t_args *args, int argc, char const **argv)
{
	init_options(args, "lem-in");
	add_desc(args, "Un programme de fourmis.");
	add_desc(args, "Il faut ecrir la fourmiliere sur l'entree standard. On pourra alors lui rediriger le contenu d'un fichier.");
	add_desc(args, "Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière par n fourmis.");
	add_option(args, "-m", "--matrix", "Show the adjacency matrix of th graph");
	add_option(args, "-r", "--road", "Show the muli-road possible and how many ants per road");
	add_option(args, "-s", "--step", "Show how many step all ants arrived in the end-room");
	add_option(args, "-E", "--explicit", "Show exactly the good errors messages");
	if (!parse_options(args, argc, argv))
		exit(0);
}

static void parse_anthill(t_anthill *house, int explicit)
{
	char			*line;
	t_parser	parse;

	line = NULL;
	parse = create_parser(house);
	while (get_next_line(0, &line) > 0)
	{
		if (parser(&parse, line, explicit) != 1)
			break ;
		free(line);
	}
}

int		main(int argc, char const **argv)
{
	t_args			args;
	t_anthill		house;
	int				nb_step;
	int				explicit;

	house = init_anthill();
	prepare_options(&args, argc, argv);
	explicit = (option_is_set(args, "-E--explicit")) ? 1 : 0;
	parse_anthill(&house, explicit);
	if (!house.nb_ants)
		no_ants(explicit);
	if (!house.start)
		no_start_room(explicit);
	if (!house.end)
		no_end_room(explicit);
	if (option_is_set(args, "-m--matrix"))
		print_matrix(house);
	dijkstra_it(&house, explicit);
	if (option_is_set(args, "-r--road"))
		show_road(house);
	nb_step = move_ants(&house);
	if (nb_step == -1)
	{
		ft_putendl_fd("ERROR", 2);
		return (1);
	}
	if (option_is_set(args, "-s--step"))
		show_nb_step(nb_step);
	return (0);
}
