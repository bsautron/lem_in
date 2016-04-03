/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:44:59 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:45:00 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <parser.h>

void		parse_anthill(t_anthill *house, int explicit)
{
	char			*line;
	t_parser		parse;

	line = NULL;
	parse = create_parser(house);
	while (get_next_line(0, &line) > 0)
	{
		if (parser(&parse, line, explicit) != 1)
			break ;
	}
}
