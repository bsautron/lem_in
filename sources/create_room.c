/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:50:32 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:50:33 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_room	*create_room(char *name, int y, int x, char type)
{
	t_room		*new;

	new = LIST_NEW(t_room);
	ft_bzero(new, sizeof(t_room));
	new->name = ft_strdup(name);
	new->type = type;
	new->y = y;
	new->x = x;
	return (new);
}
