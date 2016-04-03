/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_htab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:13:03 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:13:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhtab.h>

t_htab		create_htab(int length_max, int (*fn_hash)(char *s))
{
	t_htab			htab;
	int				i;

	i = 0;
	ft_bzero(&htab, sizeof(t_htab));
	htab.length_max = length_max;
	htab.hash = fn_hash;
	htab.array = (t_dhtab **)malloc(sizeof(t_dhtab *) * length_max);
	while (i < length_max)
		htab.array[i++] = NULL;
	return (htab);
}
