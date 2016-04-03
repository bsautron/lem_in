/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_nb_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:11:52 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:11:54 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int		sc_nb_ants(t_parser *parser, char *line, int explicit)
{
	(void)explicit;
	if (!ft_isnan(line))
	{
		parser->house->nb_ants = ft_atoi(line);
		enter_scope(parser, SC_ROOM);
		return (0);
	}
	return (-1);
}
