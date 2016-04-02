#include <lem_in.h>
#include <errors.h>

static int    remove_id_all_list(t_anthill *house, t_list_int **tab_list, int id)
{
	int   rem;
	int	i;

	rem = 0;
	i = 0;
	if (id != -1)
	{
		while (i < house->nb_rooms)
		{
			if (tab_list[i] && house->dijkstra->tab_rooms[id]->type != ROOM_START && remove_id(&tab_list[i], id))
			rem = 1;
			i++;
		}
	}
	return (rem);
}

static void init_roads(t_anthill *house)
{
	int       	nb_roads;
	t_list_int	*tmp;
	int			i;

	nb_roads = LIST_COUNT(house->dijkstra->pred[house->end->id]);
	if (house->dijkstra->pred[house->end->id]->nb == -1)
		no_roads_found();
	house->roads->nb_roads = (house->dijkstra->pred[house->end->id]->nb != -1) ? nb_roads : 0;
	house->roads->road = (t_list_int **)malloc(sizeof(t_list_int *) * (nb_roads + 1));
	house->roads->nb_steps = (int *)malloc(sizeof(int) * nb_roads);
	house->roads->nb_ants = (int *)malloc(sizeof(int) * nb_roads);
	ft_bzero(house->roads->road, sizeof(t_list_int *) * (nb_roads + 1));
	ft_bzero(house->roads->nb_ants, sizeof(int) * nb_roads);
	i = 0;
	tmp = house->dijkstra->dist[house->end->id];
	while (tmp)
	{
		house->roads->nb_steps[i] = tmp->nb;
		tmp = tmp->next;
		i++;
	}
}

static void   devide_ants(t_anthill *house)
{
	int		o;
	int		i;
	int		x;
	int		total_ants;
	int		n;

	o = 0;
	i = 1;
	total_ants = house->nb_ants;
	while (i < house->roads->nb_roads)
	{
		o += house->roads->nb_steps[i] - house->roads->nb_steps[0];
		i++;
	}
	i = 0;
	x = (house->nb_ants + o) / house->roads->nb_roads;
	while (i < house->roads->nb_roads)
	{
		n = x - (house->roads->nb_steps[i] - house->roads->nb_steps[0]);
		house->roads->nb_ants[i] = n;
		total_ants -= n;
		i++;
	}
	house->roads->nb_ants[0] += total_ants;
}

static void 	tab_list_to_tab_of_tab(t_anthill *house)
{
	int			i;
	int			j;
	t_list_int	*tmp;

	house->roads->tab_roads = (int **)malloc(sizeof(int *) * (house->roads->nb_roads + 1));
	ft_bzero(house->roads->tab_roads, sizeof(int *) * (house->roads->nb_roads + 1));
	i = 0;
	while (i < house->roads->nb_roads)
	{
		house->roads->tab_roads[i] = (int *)malloc(sizeof(int) * house->roads->nb_steps[i]);
		j = 0;
		tmp = house->roads->road[i];
		tmp = tmp->next;
		while (tmp)
		{
			house->roads->tab_roads[i][j] = tmp->nb;
			tmp = tmp->next;
			j++;
		}
		i++;
	}
}

void   get_roads(t_anthill *house)
{
	int         id;
	int         x;
	int         i;
	int         i_room;

	init_roads(house);
	i_room = 0;
	while (i_room < house->roads->nb_roads)
	{
		x = house->end->id;
		push_id(&house->roads->road[i_room], x);
		remove_id(&house->dijkstra->dist[x], house->dijkstra->dist[x]->nb);
		i = 0;
		while (i++ < house->roads->nb_steps[i_room])
		{
			if (x != -1)
			{
				id = house->dijkstra->pred[x]->nb;
				if (id != -1)
				{
					remove_id_all_list(house, house->dijkstra->pred, id);
					push_id(&house->roads->road[i_room], id);
					x = id;
				}
			}
		}
		i_room++;
	}
	tab_list_to_tab_of_tab(house);
	devide_ants(house);
}
