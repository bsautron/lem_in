#include <lem_in.h>
#include <parser.h>

int		main(int argc, char const **argv)
{
	t_args			args;
	t_anthill		house;

	init_options(&args, "lem_in");
	add_desc(&args, "Un programme de fourmis.");
	add_desc(&args, "Il faut ecrir la fourmiliere sur l'entree standard. On pourra alors lui rediriger le contenu d'un fichier.");
	add_desc(&args, "Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière par n fourmis.");
	add_option(&args, "-s", "--show", "Show anthill");
	add_option(&args, "-m", "--matrix", "Show the adjacency matrix of th graph");
	if (!parse_options(&args, argc, argv))
		return (0);

	char	*line;
	t_parser	parse;

	house = init_anthill();
	parse = create_parser(&house);

	line = NULL;
	while (get_next_line(0, &line) > 0)
		parser(&parse, line);

	if (option_is_set(args, "-m--matrix"))
		print_matrix(house);
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
