/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 20:33:01 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 20:33:11 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void fill_room(t_anthill *house, char *line, int explicit)
{
	char	**infos;

	infos = ft_strsplit(line, ' ');
	add_room(house, create_room(infos[0], ft_atoi(infos[1]), ft_atoi(infos[2]), ROOM_NORMAL), explicit);
	free(infos[0]);
	free(infos[1]);
	free(infos[2]);
	free(infos);
}

int		sc_room(t_parser *parse, char *line, int explicit)
{
	int 	ret;

	if (ft_strequ(line, "##start"))
		enter_scope(parse, SC_ROOM_START);
	else if (ft_strequ(line, "##end"))
		enter_scope(parse, SC_ROOM_END);
	else if (is_valid_room(line))
		fill_room(parse->house, line, explicit);
	else if (is_valid_connection(line))
	{
		init_dijkstra(parse->house);
		enter_scope(parse, SC_CONNECTION);
		ret = parser(parse, line, explicit);
		LIST_POP_BACK(&parse->house->saved);
		if (ret == 2)
			return (2);
	}
	else if (!ft_strnequ(line, "##", 2))
		return (-1);
	return (0);
}
