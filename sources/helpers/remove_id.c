/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:19:57 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:22:25 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

static void		re_push_minus(t_list_int **list)
{
	t_list_int	*less;

	less = LIST_NEW(t_list_int);
	less->nb = -1;
	LIST_PUSH_FRONT(list, less);
}

int				remove_id(t_list_int **list, int id)
{
	t_list_int	*tmp;
	t_list_int	*prev;
	int			ret;

	ret = 0;
	tmp = *list;
	if (tmp->nb == id)
		*list = tmp->next;
	prev = tmp;
	while (tmp)
	{
		if (tmp->nb == id)
		{
			prev->next = tmp->next;
			ret = 1;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	if (*list == NULL)
		re_push_minus(list);
	return (ret);
}
