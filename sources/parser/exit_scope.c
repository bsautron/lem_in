#include <parser.h>

void exit_scope(t_parser *parser)
{
	LIST_POP_FRONT(&parser->scope);
}
