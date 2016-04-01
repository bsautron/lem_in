#include <parser.h>

int		is_valid_room(char *line)
{
	int		pos;

	pos = 0;
	while (line[pos] > ' ' && line[pos] != '-' && ft_isprint(line[pos++]));
	if (line[pos++] != ' ')
		return (0);
	while (line[pos] > ' ' && ft_isdigit(line[pos++]));
	if (line[pos++] != ' ')
		return (0);
	while (line[pos] > ' ' && ft_isdigit(line[pos++]));
	if (pos - ft_strlen(line) == 0)
		return (1);
	return (0);
}
