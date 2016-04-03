/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_list_to_tab_of_tab.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:03:46 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:03:56 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	tab_list_to_tab_of_tab(t_anthill *house)
{
	int			i;
	int			j;
	t_list_int	*tmp;

	house->roads->tab_roads =
		(int **)malloc(sizeof(int *) * (house->roads->nb_roads + 1));
	ft_bzero(house->roads->tab_roads, sizeof(int *) * house->roads->nb_roads);
	house->roads->tab_roads[house->roads->nb_roads] = NULL;
	i = 0;
	while (i < house->roads->nb_roads)
	{
		house->roads->tab_roads[i] =
			(int *)malloc(sizeof(int) * house->roads->nb_steps[i]);
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
