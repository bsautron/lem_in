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

typedef struct	s_anthill
{
	int						nb_ant;
	int						nb_rooms;
	t_ant_list		*ants;
	t_room				*start;
	t_room				*end;
	t_room_list		*rooms;
	t_htab				htab;
	int 					**matrix_graph;
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
	char			type;
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

t_anthill     init_anthill(void);
void    			show_anthill(t_anthill house);

t_ant     new_ant(int id, int y, int x, int type);
int    add_ant(t_anthill *house, char *room);

t_room		*create_room(char *name, int y, int x, char type);
void		addtube_to_room(t_room *room, t_room *new);
int     room_is_available(t_room *room);
void		connect_room(t_anthill house, char *room1, char *room2);
void	show_room_prive(t_anthill house, char *room_name);
void		free_room(t_room *room);
void      add_room(t_anthill *house, t_room *room);

void 		dijkstra_it(t_anthill *house);

void    create_matrix(t_anthill *house);


#endif
