#include <lem_in.h>

void	show_room_prive(t_room *room)
{
	t_connection	*tmp;

	ft_putstr("Name: [");
	ft_putstr(room->name);
	ft_putendl("]");
	ft_putstr("Type: ");
	if (room->type == ROOM_START)
		ft_putendl("Start");
	else if (room->type == ROOM_END)
		ft_putendl("End");
	else
		ft_putendl("Normal");
	ft_putstr("X: ");
	ft_putnbr(room->x);
	ft_putstr(" Y: ");
	ft_putnbr(room->y);
	ft_putchar('\n');
	ft_putstr("Available: ");
	ft_putendl((room->available) ? "True" : "False");
	ft_putstr("Connection:");
	tmp = room->connection;
	while (tmp)
	{
		ft_putstr(" [");
		ft_putstr(tmp->room->name);
		ft_putstr("]");
		tmp = tmp->next;
	}
	ft_putendl("\n---");
}
