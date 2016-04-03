/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:16:34 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:16:46 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblist.h>

size_t		list_count(t_plist *list)
{
	t_plist	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
