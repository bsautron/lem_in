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
typedef struct s_room_list t_room_list;
typedef struct s_room_htab t_room_htab;
typedef struct s_ant_list t_ant_list;
typedef struct s_possible_road t_possible_road;
typedef struct s_dijsktra t_dijsktra;

typedef struct	s_anthill
{
	int						nb_ant;
	int						nb_rooms;
	t_ant_list		*ants;
	t_room				*start;
	t_room				*end;
	t_room_list		*rooms;
	t_htab				htab;
	t_possible_road	**possible;

	t_dijsktra		*dijkstra;
}								t_anthill;

typedef struct		s_ant
{
	int 		id;
	int 		y;
	int 		x;
	int			type;
}									t_ant;

struct		s_ant_list
{
	void 				*next;
	t_ant				ant;
};

struct		s_room
{
	t_room_list	*connection;
	int				id;
	char			*name;
	int				type;
	int				capacity;
	int				y;
	int				x;
	int				available;
	int				nb_ant;
	int				visited;
};

struct	s_room_list
{
	void 		*next;
	t_room	*room;
};

struct	s_room_htab
{
	void 		*next;
	char		*key;
	t_room	*room;
};

struct	s_possible_road
{
	int						nb_step;
	int						arrived;
	t_room_list		*origin;
};

typedef struct	s_list_int
{
	void 	*next;
	int		nb;
}								t_list_int;

struct	s_dijsktra
{
	int						**adjacent_matrix;
	t_room				**tab_rooms;
	t_list_int    *already;
	t_list_int    *rest;
	t_list_int    **pred;
	t_list_int    **dist;
};

t_anthill     init_anthill(void);
void    			show_anthill(t_anthill house);

t_ant     new_ant(int id, int y, int x, int type);
int    add_ant(t_anthill *house, char *room);

t_room		*create_room(char *name, int y, int x, char type);
void		addtube_to_room(t_room *room, t_room *new);
int     room_is_available(t_room *room);
void		connect_room(t_anthill *house, char *room1, char *room2);
void	show_room_prive(t_anthill house, char *room_name);
void		free_room(t_room *room);
void      add_room(t_anthill *house, t_room *room);

void 		dijkstra_it(t_anthill *house);

void 	init_dijsktra(t_anthill *house);
void   print_matrix(t_anthill house);



#endif
