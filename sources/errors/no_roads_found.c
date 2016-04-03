/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_roads_found.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:07:12 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:07:15 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	no_roads_found(int explicit)
{
	if (explicit)
	{
		ft_putendl_fd("No roads found", 2);
	}
}
