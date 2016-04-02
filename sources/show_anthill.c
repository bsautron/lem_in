#include <lem_in.h>

void    show_anthill(t_anthill house)
{
  t_room_list   *rooms;
  int           i;
  int           j;
  char          map[10][10];

  rooms = house.rooms;
  i = 0;
  while (i < 10)
  {
    j = 0;
    while (j < 10)
    {
      map[i][j] = 0;
      j++;
    }
    i++;
  }
  while (rooms)
  {
    // show_room_prive(house, rooms->room->name);
    map[rooms->room->y][rooms->room->x] = rooms->room->name[0];
    rooms = rooms->next;
  }
  i = 0;
  while (i < 10)
  {
    j = 0;
    while (j < 10)
    {
      printf("%c", (map[i][j]) ? map[i][j] : ' ');
      j++;
    }
    printf("\n");
    i++;
  }
}
