#include <parser.h>

int		sc_default(t_parser *parser, char *line, int explicit)
{
	enter_scope(parser, SC_NB_ANTS);
	(void)line;
	(void)explicit;
	return (0);
}
