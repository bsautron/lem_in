#include <parser.h>

static void connect_it(t_anthill *house, char *line, int explicit)
{
	char	**infos;

	infos = ft_strsplit(line, '-');
	connect_room(house, infos[0], infos[1], explicit);
	free(infos[0]);
	free(infos[1]);
	free(infos);
}

int		sc_connection(t_parser *parser, char *line, int explicit)
{
	if (is_valid_connection(line))
		connect_it(parser->house, line, explicit);
	else
		return (-1);
	return (0);
}
