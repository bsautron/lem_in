/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:17:11 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:17:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <liblist.h>

t_plist		*list_new(size_t size)
{
	t_plist		*new;

	new = (t_plist *)malloc(size);
	if (new)
		ft_bzero(new, size);
	return (new);
}
