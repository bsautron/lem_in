/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:59:19 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 20:03:01 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void	print_line(int *matrix_line, int n)
{
	int		j;

	j = 0;
	ft_putchar('\t');
	while (j < n)
	{
		if (j)
			ft_putstr(", ");
		ft_putnbr(matrix_line[j]);
		j++;
	}
	ft_putstr("\n");
}

void		print_matrix(t_anthill house)
{
	int	i;
	int	n;
	int	**matrix;

	if (house.dijkstra)
	{
		n = house.nb_rooms;
		matrix = house.dijkstra->adjacent_matrix;
		i = 0;
		ft_putendl("ADJACENCY MATRIX:");
		while (matrix[i])
		{
			print_line(matrix[i], n);
			i++;
		}
		ft_putstr("\n");
	}
}
