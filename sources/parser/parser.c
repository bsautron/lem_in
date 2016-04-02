#include <parser.h>
#include <errors.h>

static int 	is_not_comment(char *line)
{
	if (line && line[0] == '#' && line[1] != '#')
		return (0);
	return (1);
}

int parser(t_parser *parser, char *line, int explicit)
{
	int			ret;

	if (line && ft_strnequ(line, "##", 2) && !ft_strequ(line, "##end") && !ft_strequ(line, "##start"))
		return (1);
	if (is_not_comment(line))
	{
		ret = parser->fn_scope[parser->scope->type](parser, line, explicit);
		if (ret == -1)
		{
			print_error_parsing(parser->scope->type, line, explicit);
			return (0);
		}
		else if (ret == 2)
			return (2);
	}
	return (1);
}
