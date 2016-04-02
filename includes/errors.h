#ifndef ERRORS_H
# define ERRORS_H

void	no_ants(int explicit);
void	no_start_room(int explicit);
void	no_end_room(int explicit);
void	no_more_start_room(int explicit);
void	no_more_end_room(int explicit);
void 	no_connection(int explicit);
void 	no_roads_found(int explicit);
void 	print_error_parsing(int type, char *line, int explicit);

#endif
