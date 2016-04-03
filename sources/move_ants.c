/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 20:04:19 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 21:15:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static t_move	*create_move(int ant_id, int room_id)
{
	t_move		*new;

	new = LIST_NEW(t_move);
	new->ant_id = ant_id;
	new->room_id = room_id;
	return (new);
}

static int		change_pos(t_anthill *house, int *nb_step, int nb_bs, int i_ant)
{
	int		road_taked;

	road_taked = house->roads->road_taked[i_ant];
	if (house->roads->ants_pos[i_ant] == house->start->id)
	{
		house->roads->ants_pos[i_ant] =
			house->roads->tab_roads[nb_bs][nb_step[i_ant]];
		nb_step[i_ant]++;
		house->roads->road_taked[i_ant] = nb_bs;
		house->roads->nb_ants[road_taked]--;
		if (house->roads->nb_ants[road_taked] == 0)
			house->roads->nb_roads--;
		return (1);
	}
	else
	{
		house->roads->ants_pos[i_ant] =
			house->roads->tab_roads[road_taked][nb_step[i_ant]];
		nb_step[i_ant]++;
		return (0);
	}
}

static void		step(t_anthill *house, int *nb_step)
{
	int			i_ant;
	int			nb_ants_by_start;
	t_list_move	*list_move;

	list_move = LIST_NEW(t_list_move);
	list_move->move = NULL;
	i_ant = 0;
	nb_ants_by_start = 0;
	while (i_ant < house->nb_ants)
	{
		if (house->roads->ants_pos[i_ant] != -1)
		{
			if (change_pos(house, nb_step, nb_ants_by_start, i_ant) == 1)
				nb_ants_by_start++;
			LIST_PUSH_BACK(&list_move->move,
					create_move(i_ant, house->roads->ants_pos[i_ant]));
			if (house->roads->ants_pos[i_ant] == house->end->id
				&& ++house->nb_ants_arrived)
				house->roads->ants_pos[i_ant] = -1;
		}
		if (nb_ants_by_start >= house->roads->nb_roads && nb_ants_by_start != 0)
			break ;
		i_ant++;
	}
	LIST_PUSH_BACK(&house->list_move, list_move);
}

int				move_ants(t_anthill *house)
{
	int		nb_steps;
	int		*nb_step;
	int		i;

	if (!house->dijkstra || !house->start
			|| !house->end || !house->roads->nb_roads)
		return (-1);
	nb_steps = 0;
	house->roads->ants_pos = (int *)malloc(sizeof(int) * house->nb_ants);
	house->roads->road_taked = (int *)malloc(sizeof(int) * house->nb_ants);
	nb_step = (int *)malloc(sizeof(int) * house->nb_ants);
	ft_bzero(nb_step, sizeof(int) * house->nb_ants);
	i = 0;
	while (i < house->nb_ants)
		house->roads->ants_pos[i++] = house->start->id;
	i = 0;
	while (i < house->nb_ants)
		house->roads->road_taked[i++] = -1;
	i = 0;
	while (++nb_steps && house->nb_ants_arrived != house->nb_ants)
		step(house, nb_step);
	return (nb_steps - 1);
}
