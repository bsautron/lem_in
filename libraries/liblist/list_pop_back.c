/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 21:50:52 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 21:58:28 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblist.h>

void	list_pop_back(t_plist **list)
{
	t_plist		*tmp;

	tmp = *list;
	if (tmp)
	{
		if (!tmp->next)
			*list = NULL;
		else
		{
			while (((t_plist *)(tmp->next))->next)
				tmp = tmp->next;
			tmp->next = NULL;
		}
	}
}
