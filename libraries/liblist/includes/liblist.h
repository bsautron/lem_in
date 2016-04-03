/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblist.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:31:16 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 19:36:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLIST_H
# define LIBLIST_H

# include <libft.h>

typedef struct s_plist	t_plist;

# define LIST_NEW(X)			((X *)list_new(sizeof(X)))
# define LIST_PUSH_FRONT(X, N)	list_push_front((t_plist **)(X), (t_plist *)(N))
# define LIST_PUSH_BACK(X, N)	list_push_back((t_plist **)(X), (t_plist *)(N))
# define LIST_MAP(X, F)			l_map((t_plist*)(X),(t_plist*(*)(t_plist*))(F))
# define LIST_REMOVE(X, F)		l_rm((t_plist **)(X), (int (*)(t_plist *))(F))
# define LIST_POP_FRONT(X)		list_pop_front((t_plist **)(X))
# define LIST_COUNT(X)			list_count((t_plist *)(X))

t_plist					*list_new(size_t size);
void					list_push_front(t_plist **start, t_plist *new);
void					list_push_back(t_plist **start, t_plist *new);
void					l_map(t_plist *lst, t_plist *(*fn)(t_plist *));
void					l_rm(t_plist **list, int (*fn)(t_plist *));
size_t					list_count(t_plist *list);
void					list_pop_front(t_plist **start);

struct					s_plist
{
	void		*next;
};

#endif
