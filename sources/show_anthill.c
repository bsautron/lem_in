#include <lem_in.h>

void    show_anthill(t_anthill house)
{
  t_room_list   *rooms;

  rooms = house.rooms;
  while (rooms)
  {
    show_room_prive(house, rooms->room->name);
    rooms = rooms->next;
  }
}
