/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_connection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:11:33 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:15:34 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	connect_it(t_anthill *house, char *line, int explicit)
{
	char	**infos;
	int		ret;

	infos = ft_strsplit(line, '-');
	ret = connect_room(house, infos[0], infos[1], explicit);
	free(infos[0]);
	free(infos[1]);
	free(infos);
	return (ret);
}

int			sc_connection(t_parser *parser, char *line, int explicit)
{
	int		ret;

	if (is_valid_connection(line))
	{
		ret = connect_it(parser->house, line, explicit);
		if (ret == 0)
			return (2);
	}
	else
		return (-1);
	return (0);
}
