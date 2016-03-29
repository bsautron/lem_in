#include <lem_in.h>

static int    remove_id_all_list(t_anthill *house, t_list_int **tab_list, int id)
{
  int   rem;

  rem = 0;
  while (*tab_list)
  {
    if (house->dijkstra->tab_rooms[id]->type != ROOM_START && remove_id(&(*tab_list), id))
      rem = 1;
    tab_list++;
  }
  return (rem);
}

void   get_roads(t_anthill *house)
{
  int         id;
  int         x;
  int         i;
  int         i_room;

  house->roads->nb_road = LIST_COUNT(house->dijkstra->pred[house->nb_rooms - 1]);
  house->roads->road = (t_list_int **)malloc(sizeof(t_list_int *) * (house->roads->nb_road + 1));
  house->roads->nb_step = (int *)malloc(sizeof(int) * house->roads->nb_road);
  ft_bzero(house->roads->road, sizeof(t_list_int *) * (house->roads->nb_road + 1));
  i_room = 0;
  while (i_room < house->roads->nb_road)
  {
    x = house->end->id;
    push_id(&house->roads->road[i_room], x);
    house->roads->nb_step[i_room] = house->dijkstra->dist[house->nb_rooms - 1]->nb;
    remove_id(&house->dijkstra->dist[x], house->dijkstra->dist[x]->nb);
    i = 0;
    while (i++ < house->roads->nb_step[i_room])
    {
      id = house->dijkstra->pred[x]->nb;
      remove_id_all_list(house, house->dijkstra->pred, id);
      push_id(&house->roads->road[i_room], id);
      x = id;
    }
    i_room++;
  }
}
