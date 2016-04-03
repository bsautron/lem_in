/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htab_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:14:29 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:14:30 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libhtab.h>

void	htab_set(t_htab *htab, t_dhtab *value)
{
	int		index;

	index = htab->hash(value->key) % htab->length_max;
	LIST_PUSH_BACK(&htab->array[index], value);
	htab->length++;
}
