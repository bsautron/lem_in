#include <parser.h>

int		sc_nb_ants(t_parser *parser, char *line)
{
	if (!ft_isnan(line))
	{
		parser->house->nb_ants = ft_atoi(line);
		enter_scope(parser, SC_ROOM);
		return (0);
	}
	return (-1);
}
