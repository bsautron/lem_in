/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_parsing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:07:20 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:10:04 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <parser.h>

void	print_error_parsing(int type, char *line, int explicit)
{
	char	*err_mes[NB_SCOPE];

	if (explicit)
	{
		err_mes[SC_NB_ANTS] = "The line is not a number";
		err_mes[SC_ROOM] = "The line is not a valid room";
		err_mes[SC_ROOM_START] = err_mes[SC_ROOM];
		err_mes[SC_ROOM_END] = err_mes[SC_ROOM];
		err_mes[SC_CONNECTION] = "The line is not a valid connection";
		ft_putstr_fd("[\"", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("\"]: ", 2);
		ft_putendl_fd(err_mes[type], 2);
	}
}
