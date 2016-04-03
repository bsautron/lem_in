/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_it.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 20:03:10 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 20:32:44 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <errors.h>

static void	push_pop_id(t_dijkstra *dijkstra, int id)
{
	if (remove_id(&dijkstra->rest, id))
		push_id(&dijkstra->already, id);
}

static void	push_dist_pred(t_dijkstra *d, t_list_int *tmp, int min_dist, int x)
{
	t_list_int	*new;

	new = LIST_NEW(t_list_int);
	new->nb = min_dist + d->adjacent_matrix[x][tmp->nb];
	LIST_PUSH_BACK(&d->dist[tmp->nb], new);
	new = LIST_NEW(t_list_int);
	new->nb = x;
	LIST_PUSH_BACK(&d->pred[tmp->nb], new);
}

static void	fill_it(t_dijkstra *d, int id)
{
	int			x;
	t_list_int	*tmp;
	int			min;

	x = id;
	push_pop_id(d, x);
	tmp = d->rest;
	while (tmp)
	{
		if (d->adjacent_matrix[x][tmp->nb])
		{
			min = find_min_list_int(d->dist[x]);
			if (d->dist[tmp->nb]->nb == -1)
			{
				if (min == -1)
					d->dist[tmp->nb]->nb = 1;
				else
					d->dist[tmp->nb]->nb = min + d->adjacent_matrix[x][tmp->nb];
				d->pred[tmp->nb]->nb = x;
			}
			else
				push_dist_pred(d, tmp, min, x);
		}
		tmp = tmp->next;
	}
}

static int	find_min(t_anthill *house)
{
	t_list_int	*tmp;
	int			min;
	int			ret;

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

void		dijkstra_it(t_anthill *house, int explicit)
{
	int	x;

	if (!house->dijkstra)
		no_connection(explicit);
	else if (house->start && house->end)
	{
		house->dijkstra->dist[house->start->id]->nb = 0;
		x = find_min(house);
		fill_it(house->dijkstra, x);
		while (house->dijkstra->already != NULL && (x = find_min(house)) != -1)
			fill_it(house->dijkstra, x);
		get_roads(house, explicit);
	}
}
