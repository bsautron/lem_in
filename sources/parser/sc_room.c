#include <parser.h>

static void fill_room(t_anthill *house, char *line, int explicit)
{
	char	**infos;

	infos = ft_strsplit(line, ' ');
	add_room(house, create_room(infos[0], ft_atoi(infos[1]), ft_atoi(infos[2]), ROOM_NORMAL), explicit);
	free(infos[0]);
	free(infos[1]);
	free(infos[2]);
	free(infos);
}

int		sc_room(t_parser *parse, char *line, int explicit)
{
	if (ft_strequ(line, "##start"))
		enter_scope(parse, SC_ROOM_START);
	else if (ft_strequ(line, "##end"))
		enter_scope(parse, SC_ROOM_END);
	else if (is_valid_room(line))
		fill_room(parse->house, line, explicit);
	else if (is_valid_connection(line))
	{
		init_dijsktra(parse->house);
		enter_scope(parse, SC_CONNECTION);
		parser(parse, line, explicit);
	}
	else if (!ft_strnequ(line, "##", 2))
		return (-1);
	return (0);
}
