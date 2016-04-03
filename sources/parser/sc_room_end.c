/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_room_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:12:12 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:16:57 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static int	fill_room(t_anthill *house, char *line, int explicit)
{
	char	**infos;
	int		ret;

	infos = ft_strsplit(line, ' ');
	ret = add_room(house, create_room(infos[0],
				ft_atoi(infos[1]), ft_atoi(infos[2]), ROOM_END), explicit);
	free(infos[0]);
	free(infos[1]);
	free(infos[2]);
	free(infos);
	return (ret);
}

int			sc_room_end(t_parser *parser, char *line, int explicit)
{
	int		ret;

	if (is_valid_room(line))
	{
		exit_scope(parser);
		ret = fill_room(parser->house, line, explicit);
		if (ret == 0)
			return (-1);
		else if (ret == 2)
			return (2);
	}
	else
		return (-1);
	return (0);
}
