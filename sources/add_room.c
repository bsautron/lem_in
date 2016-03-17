#include <lem_in.h>

void      add_room(t_anthill *house, t_room *room)
{
  t_room_list   *new_l;
  t_room_htab   *new_h;

  new_l = LIST_NEW(t_room_list);
  new_l->room = room;
  new_h = LIST_NEW(t_room_htab);
  new_h->key = room->name;
  new_h->room = room;
  LIST_PUSH_BACK(&house->rooms, new_l);
  HTAB_SET(&house->htab, new_h);
}
