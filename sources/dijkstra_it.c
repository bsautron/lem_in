#include <lem_in.h>
#include <errors.h>

static void push_pop_id(t_anthill *house, int id)
{
	if (remove_id(&house->dijkstra->rest, id))
	push_id(&house->dijkstra->already, id);
}

static void fill_it(t_anthill *house, int id)
{
	int         x;
	t_list_int  *tmp;
	t_list_int  *new;
	int         min_dist;

	x = id;
	push_pop_id(house, x);
	tmp = house->dijkstra->rest;
	while (tmp)
	{
		if (house->dijkstra->adjacent_matrix[x][tmp->nb])
		{
			min_dist = find_min_list_int(house->dijkstra->dist[x]);
			if (house->dijkstra->dist[tmp->nb]->nb == -1)
			{
				if (min_dist == -1)
				house->dijkstra->dist[tmp->nb]->nb = 1;
				else
				house->dijkstra->dist[tmp->nb]->nb = min_dist + house->dijkstra->adjacent_matrix[x][tmp->nb];
				house->dijkstra->pred[tmp->nb]->nb = x;
			}
			else
			{
				new = LIST_NEW(t_list_int);
				new->nb = min_dist + house->dijkstra->adjacent_matrix[x][tmp->nb];
				LIST_PUSH_BACK(&house->dijkstra->dist[tmp->nb], new);
				new = LIST_NEW(t_list_int);
				new->nb = x;
				LIST_PUSH_BACK(&house->dijkstra->pred[tmp->nb], new);
			}
		}
		tmp = tmp->next;
	}
}

static int  find_min(t_anthill *house)
{
	t_list_int    *tmp;
	int           min;
	int           ret;

	tmp = house->dijkstra->rest;
	ret = -1;
	min = -1;
	while (tmp)
	{
		if (house->dijkstra->tab_rooms[tmp->nb]->type != ROOM_END)
		{
			if ((house->dijkstra->dist[tmp->nb]->nb != -1
				&& min == -1)
				|| (house->dijkstra->dist[tmp->nb]->nb != -1
					&& house->dijkstra->dist[tmp->nb]->nb < min))
			{
				min = house->dijkstra->dist[tmp->nb]->nb;
				ret = tmp->nb;
			}
		}
		tmp = tmp->next;
	}
	return (ret);
}

void    dijkstra_it(t_anthill *house, int explicit)
{
	int     x;

	if (!house->dijkstra)
		no_connection(explicit);
	else
	{
		house->dijkstra->dist[house->start->id]->nb = 0;
		x = find_min(house);
		fill_it(house, x);
		while (house->dijkstra->already != NULL && (x = find_min(house)) != -1)
		fill_it(house, x);
		get_roads(house, explicit);
	}
}
