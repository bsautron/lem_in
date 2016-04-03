/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_more_end_room.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:06:21 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:06:24 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	no_more_end_room(int explicit)
{
	if (explicit)
	{
		ft_putendl_fd("Too much end-room added", 2);
	}
}
