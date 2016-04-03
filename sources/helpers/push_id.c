/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_id.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:19:43 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:19:54 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	push_id(t_list_int **list, int id)
{
	t_list_int	*new;

	new = LIST_NEW(t_list_int);
	new->nb = id;
	LIST_PUSH_FRONT(list, new);
}
