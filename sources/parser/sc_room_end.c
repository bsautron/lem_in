#include <parser.h>

static void fill_room(t_anthill *house, char *line)
{
	char	**infos;

	infos = ft_strsplit(line, ' ');
	add_room(house, create_room(infos[0], ft_atoi(infos[1]), ft_atoi(infos[2]), ROOM_END));
	free(infos[0]);
	free(infos[1]);
	free(infos[2]);
	free(infos);
}

int		sc_room_end(t_parser *parser, char *line)
{
	if (is_valid_room(line))
	{
		exit_scope(parser);
		fill_room(parser->house, line);
	}
	else
		return (-1);
	return (0);
}
