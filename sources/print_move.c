/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:44:08 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:44:09 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_move(t_anthill house, t_list_move *l_move)
{
	while (l_move)
	{
		while (l_move->move)
		{
			ft_putchar('L');
			ft_putnbr(l_move->move->ant_id + 1);
			ft_putchar('-');
			ft_putstr(house.dijkstra->tab_rooms[l_move->move->room_id]->name);
			if (l_move->move->next)
				ft_putstr(" ");
			l_move->move = l_move->move->next;
		}
		ft_putchar('\n');
		l_move = l_move->next;
	}
}
