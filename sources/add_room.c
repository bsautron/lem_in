#include <lem_in.h>
#include <errors.h>

void      add_hl_room(t_anthill *house, t_room *room)
{
  t_room_list   *new_l;
  t_room_htab   *new_h;

  room->id = house->nb_rooms++;
  new_l = LIST_NEW(t_room_list);
  new_l->room = room;
  new_h = LIST_NEW(t_room_htab);
  new_h->key = room->name;
  new_h->room = room;
  LIST_PUSH_BACK(&house->rooms, new_l);
  HTAB_SET(&house->htab, new_h);
  if (room->type == ROOM_START)
    house->start = room;
  else if (room->type == ROOM_END)
    house->end = room;
}

void      add_room(t_anthill *house, t_room *room)
{
  if (room->type == ROOM_START && house->start != 0)
    no_more_start_room();
  else if (room->type == ROOM_END && house->end != 0)
    no_more_end_room();
  else
    add_hl_room(house, room);
}
