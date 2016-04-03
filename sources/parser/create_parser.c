/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:10:42 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:16:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_parser	create_parser(t_anthill *house)
{
	t_parser	parse;

	ft_bzero(&parse, sizeof(t_parser));
	parse.house = house;
	parse.fn_scope[SC_DEFAULT] = &sc_default;
	parse.fn_scope[SC_NB_ANTS] = &sc_nb_ants;
	parse.fn_scope[SC_ROOM] = &sc_room;
	parse.fn_scope[SC_ROOM_START] = &sc_room_start;
	parse.fn_scope[SC_ROOM_END] = &sc_room_end;
	parse.fn_scope[SC_CONNECTION] = &sc_connection;
	enter_scope(&parse, SC_DEFAULT);
	parser(&parse, NULL, 0);
	return (parse);
}
