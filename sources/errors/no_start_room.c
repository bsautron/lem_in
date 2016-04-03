/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_start_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:07:03 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:07:06 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	no_start_room(int explicit)
{
	if (explicit)
	{
		ft_putendl_fd("Please create a start room", 2);
	}
}
