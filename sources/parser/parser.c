#include <parser.h>
#include <errors.h>

static int 	is_not_comment(char *line)
{
	if (line && line[0] == '#' && line[1] != '#')
		return (0);
	return (1);
}

void parser(t_parser *parser, char *line)
{
	if (is_not_comment(line))
	{
		if (parser->fn_scope[parser->scope->type](parser, line) == -1)
		{
			print_error_parsing(parser->scope->type, line);
			exit(1);
		}
	}
}
