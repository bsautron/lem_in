/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_connection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:06:47 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:06:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	no_connection(int explicit)
{
	if (explicit)
	{
		ft_putendl_fd("No connection detected", 2);
	}
}
