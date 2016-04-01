#include <parser.h>

void enter_scope(t_parser *parser, int type)
{
	t_scope			*new;

	new = LIST_NEW(t_scope);
	new->type = type;
	LIST_PUSH_FRONT(&parser->scope, new);
	parser->nb_scope++;
	// printf("I enter to scope_id %d\n", type);
}
