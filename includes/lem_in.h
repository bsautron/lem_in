/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 19:49:56 by bsautron          #+#    #+#             */
/*   Updated: 2016/04/03 21:02:42 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <liblist.h>
# include <libhtab.h>
# include <libargs.h>
# include <stdio.h>//

# define ROOM_NORMAL		0
# define ROOM_START			1
# define ROOM_END			2

typedef struct s_room		t_room;
typedef struct s_room_list	t_room_list;
typedef struct s_room_htab	t_room_htab;
typedef struct s_dijkstra	t_dijkstra;
typedef struct s_roads		t_roads;
typedef struct s_line		t_line;
typedef struct s_list_move	t_list_move;
typedef struct s_move		t_move;

typedef struct	s_anthill
{
	int				nb_ants;
	int				nb_rooms;
	int				nb_ants_arrived;
	t_room			*start;
	t_room			*end;
	t_room_list		*rooms;
	t_htab			htab;
	t_dijkstra		*dijkstra;
	t_roads 		*roads;
	t_line			*saved;
	t_list_move		*list_move;
}				t_anthill;

struct	s_line
{
	void 	*next;
	char	*line;
};

struct	s_room
{
	int		id;
	char	*name;
	int		type;
	int		y;
	int		x;
};

struct	s_room_list
{
	void 	*next;
	t_room	*room;
};

struct	s_room_htab
{
	void 	*next;
	char	*key;
	t_room	*room;
};

typedef struct	s_list_int
{
	void 	*next;
	int		nb;
}				t_list_int;

struct		s_roads
{
	int			nb_roads;
	t_list_int	**road;
	int			*nb_steps;
	int			*nb_ants;
	int			**tab_roads;
	int			*road_taked;
	int			*ants_pos;
};

struct	s_dijkstra
{
	int				**adjacent_matrix;
	t_room			**tab_rooms;
	t_list_int		*already;
	t_list_int		*rest;
	t_list_int		**pred;
	t_list_int		**dist;
	t_list_int		**road;
};

struct	s_list_move
{
	void 	*next;
	t_move 	*move;
};

struct	s_move
{
	void 	*next;
	int		ant_id;
	int		room_id;
};

t_anthill	init_anthill(void);
t_room		*create_room(char *name, int y, int x, char type);
int			connect_room(t_anthill *house, char *room1, char *room2, int explicit);
void		free_room(t_room *room);
int			add_room(t_anthill *house, t_room *room, int explicit);
void		dijkstra_it(t_anthill *house, int explicit);
void		init_dijkstra(t_anthill *house);
void		print_matrix(t_anthill house);
void		get_roads(t_anthill *house, int explicit);
int			move_ants(t_anthill *house);
int			find_min_list_int(t_list_int *list);
void		push_id(t_list_int **list, int id);
int			remove_id(t_list_int **list, int id);
void		tab_list_to_tab_of_tab(t_anthill *house);


#endif
