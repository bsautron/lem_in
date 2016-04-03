/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_end_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:06:06 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:06:59 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	no_end_room(int explicit)
{
	if (explicit)
	{
		ft_putendl_fd("Please create a end room", 2);
	}
}
