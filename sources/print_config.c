/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 22:44:02 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 22:44:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		print_config(t_line *saved)
{
	while (saved)
	{
		ft_putendl(saved->line);
		saved = saved->next;
	}
	ft_putchar('\n');
}
