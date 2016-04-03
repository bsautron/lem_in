/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htab_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:14:32 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:14:34 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhtab.h>

t_dhtab	*htab_get(t_htab htab, char *key)
{
	t_dhtab		*tmp;

	tmp = htab.array[htab.hash(key) % htab.length_max];
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
