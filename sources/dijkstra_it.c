#include <lem_in.h>

void    dijkstra_it(t_anthill *house)
{
  char        **names;
  t_room_list *room_l;
  int         n;
  int         i;

  n = house->nb_rooms;
  names = (char **)malloc(sizeof(char *) * (n + 1));
  room_l = house->rooms;
  while (room_l)
  {
    names[room_l->room->id] = room_l->room->name;
    room_l = room_l->next;
  }
  i = 0;
  printf("|");
  while (i < n)
  {
    printf("%10s|", names[i]);
    i++;
  }
  printf("\n");
}
