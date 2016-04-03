/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_default.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:11:46 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:11:49 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int		sc_default(t_parser *parser, char *line, int explicit)
{
	enter_scope(parser, SC_NB_ANTS);
	(void)line;
	(void)explicit;
	return (0);
}
