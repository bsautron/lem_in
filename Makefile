CC = gcc
NAME = lem_in
CFLAGS = -Wextra -Wall -Werror

LIBS = -L./libft -lft
LIBS_NAME = libft/libft.a

SRC = main.c \
	  create_room.c \
	  addtube_to_room.c \
	  connect_room.c \
	  show_room_prive.c \
	  free_room.c \
	  \
	  list_new.c \
	  list_push_front.c \
	  list_push_back.c

INC_DIR = includes/
INC_FILES = lem_in.h \
			plist.h

INC_DIR_OTHER = libft/includes/

OBJ_DIR = .obj/
OBJ = $(SRC:%.c=.obj/%.o)

all: dor libs $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^ $(LIBS) -g
	@echo "\033[32mReady!\033[0m"

dor:
	@mkdir -pv $(OBJ_DIR)

libs:
	@make -C libft/

.obj/%.o: %.c $(addprefix $(INC_DIR), $(INC_FILES)) $(LIB_NAME)
	@echo "\033[33m 	$<"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(INC_DIR_OTHER) -o $@ -c $< -g

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_DIR) 2> /dev/null || env -i

fclean: clean
	rm -f $(NAME)

re: fclean all
