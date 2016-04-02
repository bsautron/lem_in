#include <lem_in.h>

void	connect_room(t_anthill *house, char *room1, char *room2)
{
	t_room_htab		*hroom1;
	t_room_htab		*hroom2;

	hroom1 = HTAB_GET(house->htab, t_room_htab, room1);
	hroom2 = HTAB_GET(house->htab, t_room_htab, room2);
	if (!hroom1)
	{
		ft_putstr_fd("Room [", 2);
		ft_putstr_fd(room1, 2);
		ft_putendl_fd("] doesn't exit", 2);
		exit(1);
	}
	if (!hroom2)
	{
		ft_putstr_fd("Room [", 2);
		ft_putstr_fd(room2, 2);
		ft_putendl_fd("] doesn't exit", 2);
		exit(1);
	}
	house->dijkstra->adjacent_matrix[hroom1->room->id][hroom2->room->id] = 1;
	house->dijkstra->adjacent_matrix[hroom2->room->id][hroom1->room->id] = 1;
}
