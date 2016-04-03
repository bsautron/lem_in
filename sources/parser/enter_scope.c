/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_scope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:10:51 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:10:58 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	enter_scope(t_parser *parser, int type)
{
	t_scope			*new;

	new = LIST_NEW(t_scope);
	new->type = type;
	LIST_PUSH_FRONT(&parser->scope, new);
	parser->nb_scope++;
}
