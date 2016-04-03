/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_more_start_room.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:06:30 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:06:40 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	no_more_start_room(int explicit)
{
	if (explicit)
	{
		ft_putendl_fd("Too much start-room added", 2);
	}
}
