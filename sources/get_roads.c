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

static void init_roads(t_anthill *house)
{
  int       nb_roads;

  nb_roads = LIST_COUNT(house->dijkstra->pred[house->nb_rooms - 1]);
  house->roads->nb_roads = nb_roads;
  house->roads->road = (t_list_int **)malloc(sizeof(t_list_int *) * (nb_roads + 1));
  house->roads->nb_steps = (int *)malloc(sizeof(int) * nb_roads);
  house->roads->nb_ants = (int *)malloc(sizeof(int) * nb_roads);
  ft_bzero(house->roads->road, sizeof(t_list_int *) * (nb_roads + 1));
  ft_bzero(house->roads->nb_ants, sizeof(int) * nb_roads);
  ft_bzero(house->roads->nb_steps, sizeof(int) * nb_roads);
}

static int  count_total_step(t_anthill *house)
{
  int     i;
  int     res;

  res = 0;
  i = 0;
  while (i < house->roads->nb_roads)
    res += house->roads->nb_steps[i++];
  return (res);
}

static void   devide_ants(t_anthill *house)
{
  int     i;
  int     total_step;
  int     current_ants;
  int     nb_ants;

  i = 0;
  current_ants = house->nb_ants;
  total_step = count_total_step(house);
  while (i < house->roads->nb_roads)
  {
    if (i + 1 >= house->roads->nb_roads)
      house->roads->nb_ants[i] = current_ants;
    else
    {
      nb_ants = ((double)house->roads->nb_steps[i] / (double)total_step) * house->nb_ants;
      house->roads->nb_ants[i] = nb_ants;
      current_ants -= nb_ants;
    }
    printf("%d\n", house->roads->nb_ants[i]);
    i++;
  }
}

void   get_roads(t_anthill *house)
{
  int         id;
  int         x;
  int         i;
  int         i_room;

  init_roads(house);
  i_room = 0;
  while (i_room < house->roads->nb_roads)
  {
    x = house->end->id;
    push_id(&house->roads->road[i_room], x);
    house->roads->nb_steps[i_room] = house->dijkstra->dist[house->nb_rooms - 1]->nb;
    remove_id(&house->dijkstra->dist[x], house->dijkstra->dist[x]->nb);
    i = 0;
    while (i++ < house->roads->nb_steps[i_room])
    {
      id = house->dijkstra->pred[x]->nb;
      remove_id_all_list(house, house->dijkstra->pred, id);
      push_id(&house->roads->road[i_room], id);
      x = id;
    }
    i_room++;
  }
  devide_ants(house);
}
