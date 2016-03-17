#include <lem_in.h>

void    show_anthill(t_anthill house)
{
  t_room_list   *rooms;
  t_room        *room;

  rooms = house.rooms;
  while (rooms)
  {
    room = rooms->room;
    printf("%10s(%2d:%2d)\n", room->name, room->y, room->x);
    rooms = rooms->next;
  }
}
