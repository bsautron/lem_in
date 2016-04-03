# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/03 19:49:40 by bsautron          #+#    #+#              #
#    Updated: 2016/04/03 20:33:44 by bsautron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
DEPENDENCIES = libft \
				liblist \
				libhash \
				libhtab \
				libargs
SOURCES = create_room.c \
			connect_room.c \
			free_room.c \
			add_room.c \
			\
			init_anthill.c \
			\
			init_dijkstra.c \
			dijkstra_it.c \
			print_matrix.c \
			get_roads.c \
			move_ants.c \
			\
			helpers/find_min_list_int.c \
			helpers/push_id.c \
			helpers/remove_id.c \
			\
			parser/create_parser.c \
			parser/parser.c \
			parser/enter_scope.c \
			parser/exit_scope.c \
			parser/is_valid_room.c \
			parser/is_valid_connection.c \
			parser/sc_default.c \
			parser/sc_nb_ants.c \
			parser/sc_room.c \
			parser/sc_room_start.c \
			parser/sc_room_end.c \
			parser/sc_connection.c \
			\
			errors/no_ants.c \
			errors/no_start_room.c \
			errors/no_end_room.c \
			errors/no_more_start_room.c \
			errors/no_more_end_room.c \
			errors/no_roads_found.c \
			errors/no_connection.c \
			errors/print_error_parsing.c \

SOURCES_FOLDER = sources
OTHER_FOLDER = errors \
				parser \
				helpers

CC = clang
CFLAGS = -Wextra -Wall -Werror
TEST_FORDER = test
INCLUDES_FOLDER = includes
OBJECTS_FOLDER = .objects
MAIN = main.c
MAIN_OBJECT = $(OBJECTS_FOLDER)/$(MAIN:.c=.o)
INCLUDES = lem_in.h \
			parser.h \
			errors.h

SOURCES_DEPENDENCIES = $(foreach dep, $(DEPENDENCIES), libraries/$(dep)/$(dep).a)
INCLUDES_LIBRARIES = $(foreach dep,$(DEPENDENCIES),-I libraries/$(dep)/includes)
HEADERS_LIBRARIES = $(foreach dep,$(DEPENDENCIES),libraries/$(dep)/includes/$(dep).h)
MAKE_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make -C libraries/$(dep);)
REBUILD_LIBRARIES = $(foreach dep,$(DEPENDENCIES),make re -C libraries/$(dep);)

OBJECTS = $(SOURCES:%.c=%.o)

all: init makelib $(NAME)

rebuild: fclean init rebuildlib $(NAME)

makelib:
	$(MAKE_LIBRARIES)

rebuildlib:
	$(REBUILD_LIBRARIES)
	make re

init:
	mkdir -p $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)
	$(foreach folder, $(OTHER_FOLDER), mkdir -p $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/$(folder);)

$(NAME): $(MAIN_OBJECT) $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJECT) $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS)) $(SOURCES_DEPENDENCIES)

$(MAIN_OBJECT): $(MAIN)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $(MAIN_OBJECT) -c $(MAIN) $(INCLUDES_LIBRARIES)

$(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, %.o): $(SOURCES_FOLDER)/%.c $(addprefix $(INCLUDES_FOLDER)/, $(INCLUDES)) $(HEADERS_LIBRARIES)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -o $@ -c $< $(INCLUDES_LIBRARIES)

clean:
	rm -f $(addprefix $(OBJECTS_FOLDER)/$(SOURCES_FOLDER)/, $(OBJECTS))
	rm -f $(MAIN_OBJECT)
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all
