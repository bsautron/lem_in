#include <lem_in.h>

void	show_room_prive(t_anthill house, char *room_name)
{
	t_room_list	*tmp;
	t_room_htab *hroom;
	t_room			*room;

	hroom = HTAB_GET(house.htab, t_room_htab, room_name);
	room = hroom->room;
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
	ft_putstr("Y: ");
	ft_putnbr(room->y);
	ft_putstr(" X: ");
	ft_putnbr(room->x);
	ft_putchar('\n');
	ft_putstr("Available: ");
	ft_putendl((room->available) ? "True" : "False");
	ft_putstr("Nb ants: ");
	ft_putnbr(room->nb_ant);
	ft_putchar('\n');
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
