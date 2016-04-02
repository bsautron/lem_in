#ifndef PARSER_H
# define PARSER_H

# include <lem_in.h>

# define NB_SCOPE		6

typedef struct s_parser		t_parser;

enum	e_scope_type
{
	SC_DEFAULT,
	SC_NB_ANTS,
	SC_ROOM,
	SC_ROOM_START,
	SC_ROOM_END,
	SC_CONNECTION
};

typedef struct	s_scope
{
	void 	*next;
	int		type;
}				t_scope;

struct	s_parser
{
	t_anthill	*house;
	int			nb_scope;
	int			current_scope;
	t_scope		*scope;
	int 		(*fn_scope[NB_SCOPE])(t_parser *, char *);
};

t_parser	create_parser(t_anthill *house);
void 		parser(t_parser *parser, char *line);
void 		enter_scope(t_parser *parser, int type);
void 		exit_scope(t_parser *parser);
int			is_valid_room(char *line);
int			is_valid_connection(char *line);
int			sc_default(t_parser *parser, char *line);
int			sc_nb_ants(t_parser *parser, char *line);
int			sc_room(t_parser *parser, char *line);
int			sc_room_start(t_parser *parser, char *line);
int			sc_room_end(t_parser *parser, char *line);
int			sc_connection(t_parser *parser, char *line);

#endif
