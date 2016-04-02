#include <parser.h>

static int fill_room(t_anthill *house, char *line, int explicit)
{
	char	**infos;
	int		ret;

	infos = ft_strsplit(line, ' ');
	ret = add_room(house, create_room(infos[0], ft_atoi(infos[1]), ft_atoi(infos[2]), ROOM_START), explicit);
	free(infos[0]);
	free(infos[1]);
	free(infos[2]);
	free(infos);
	return (ret);
}

int		sc_room_start(t_parser *parser, char *line, int explicit)
{
	int		ret;

	if (is_valid_room(line))
	{
		exit_scope(parser);
		ret = fill_room(parser->house, line, explicit);
		if (ret == 0)
			return (-1);
		else if (ret == 2)
			return (2);
	}
	else
		return (-1);
	return (0);
}
