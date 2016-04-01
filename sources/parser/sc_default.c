#include <parser.h>

int		sc_default(t_parser *parser, char *line)
{
	enter_scope(parser, SC_NB_ANTS);
	(void)line;
	return (0);
}
