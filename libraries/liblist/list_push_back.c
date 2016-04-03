/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:18:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:18:10 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblist.h>

void		list_push_back(t_plist **start, t_plist *new)
{
	t_plist	*tmp;

	if (!start)
		start = &new;
	tmp = *start;
	if (!(*start))
		*start = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
