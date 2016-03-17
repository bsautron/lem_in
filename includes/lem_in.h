#ifndef LEM_IN_H
# define LEM_IN_H

# include <libft.h>
# include <liblist.h>
# include <libhtab.h>
# include <stdio.h>//

# define ROOM_NORMAL		0
# define ROOM_START			1
# define ROOM_END			2

typedef struct s_room		t_room;
typedef struct s_room_list t_room_list;
typedef struct s_room_htab t_room_htab;

typedef struct		s_connection
{
	void	*next;
	t_room	*room;
}					t_connection;

struct		s_room
{
	t_connection	*connection; // a linterieur une list chainé
	char			*name;
	char			type;
	int				capacity;
	int				available;
	int				y;
	int				x;
};

typedef struct	s_anthill
{
	t_room_list		*rooms;
	t_htab				htab;
}								t_anthill;

struct	s_room_list
{
	void 		*next;
	t_room	*room;
}								;

struct	s_room_htab
{
	void 		*next;
	char		*key;
	t_room	*room;
}								;

t_anthill     init_anthill(void);
void    			show_anthill(t_anthill house);


t_room		*create_room(char *name, int x, int y, char type);
void		addtube_to_room(t_room *room, t_room *new);
void		connect_room(t_room *room1, t_room *room2);
void		show_room_prive(t_room *room);
void		free_room(t_room *room);
void      add_room(t_anthill *house, t_room *room);


#endif
