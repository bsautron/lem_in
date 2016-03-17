#include <lem_in.h>

int    add_ant(t_anthill *house, char *room)
{
  t_room_htab   *hroom;
  t_ant_list    *ant_l;

  hroom = HTAB_GET(house->htab, t_room_htab, room);
  if (room_is_available(hroom->room))
  {
    ant_l = LIST_NEW(t_ant_list);
    ant_l->ant = new_ant(house->nb_ant++, hroom->room->y, hroom->room->x, 0);
    hroom->room->nb_ant++;
    LIST_PUSH_FRONT(&house->ants, ant_l);
    if (hroom->room->nb_ant >= hroom->room->capacity)
      hroom->room->available = 0;
    return (1);
  }
  return (0);
}
