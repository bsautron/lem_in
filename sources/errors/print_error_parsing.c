#include <lem_in.h>
#include <parser.h>

void print_error_parsing(int type, char *line, int explicit)
{
	char	*err_mes[NB_SCOPE];

	if (explicit)
	{
		err_mes[SC_NB_ANTS] = "The line is not a number";
		err_mes[SC_ROOM] = "The line is not a valid room (nom::string coord_x::int coord_y::int)";
		err_mes[SC_ROOM_START] = err_mes[SC_ROOM];
		err_mes[SC_ROOM_END] = err_mes[SC_ROOM];
		err_mes[SC_CONNECTION] = "The line is not a valid connection (nom1::string-nom2::string)";
		ft_putstr_fd("[\"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\"]: ", 2);
		ft_putendl_fd(err_mes[type], 2);
	}
}
