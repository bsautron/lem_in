#include <parser.h>

void exit_scope(t_parser *parser)
{
	printf("%d\n", parser->scope->type);
	LIST_POP_FRONT(&parser->scope);
	printf("%d\n", parser->scope->type);
}
