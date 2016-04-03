/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:11:14 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:15:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int		is_valid_room(char *line)
{
	int		pos;

	pos = 0;
	if (line[0] == 'L')
		return (0);
	while (line[pos] > ' ' && line[pos] != '-' && ft_isprint(line[pos]))
		pos++;
	if (line[pos++] != ' ')
		return (0);
	while (line[pos] > ' ' && ft_isdigit(line[pos]))
		pos++;
	if (line[pos++] != ' ')
		return (0);
	while (line[pos] > ' ' && ft_isdigit(line[pos]))
		pos++;
	if (pos - ft_strlen(line) == 0)
		return (1);
	return (0);
}
