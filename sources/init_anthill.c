/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:50:42 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:50:50 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <libhash.h>

t_anthill	init_anthill(void)
{
	t_anthill	new;

	ft_bzero(&new, sizeof(t_anthill));
	new.htab = HTAB_CREATE(100, &hash_pour_les_nuls);
	new.roads = (t_roads *)malloc(sizeof(t_roads));
	return (new);
}
