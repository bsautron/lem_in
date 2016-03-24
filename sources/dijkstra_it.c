#include <lem_in.h>

static void print_list(char *name, t_list_int *list)
{
  t_list_int    *tmp;

  tmp = list;
  printf("%s: ", name);
  while (tmp)
  {
    printf("%d ", tmp->nb);
    tmp = tmp->next;
  }
  printf("%s\n", "");
}

static void print_tab_list(char *name, t_list_int **tab)
{
  int     i;
  t_list_int    *tmp;

  i = 0;
  printf("%s: ", name);
  while (tab[i])
  {
    tmp = tab[i];
    while (tmp)
    {
      if (tmp->nb == -1)
        printf("%s", "-");
      else
        printf("%d", tmp->nb);
      tmp = tmp->next;
      if (tmp)
        printf(",");
    }
    printf(" ");
    i++;
  }
  printf("%s\n", "");
}

static int remove_id(t_list_int **list, int id)
{
  t_list_int    *tmp;
  t_list_int    *prev;

  tmp = *list;
  if (tmp->nb == id)
    *list = tmp->next;
  prev = tmp;
  while (tmp)
  {
    if (tmp->nb == id)
    {
      prev->next = tmp->next;
      return (1);
    }
    prev = tmp;
    tmp = tmp->next;
  }
  return (0);
}

static void push_id(t_list_int **list, int id)
{
  t_list_int    *new;

  new = LIST_NEW(t_list_int);
  new->nb = id;
  LIST_PUSH_FRONT(list, new);
}

static void push_pop_id(t_anthill *house, int id)
{
  if (remove_id(&house->dijkstra->rest, id))
    push_id(&house->dijkstra->already, id);
}

static int  find_min_list_int(t_list_int *list)
{
  t_list_int    *tmp;
  int           min;

  tmp = list;
  min = tmp->nb;
  while (tmp)
  {
    if (tmp->nb < min)
      min = tmp->nb;
    tmp = tmp->next;
  }
  return (min);
}

static void fill_it(t_anthill *house, int id)
{
  int         x;
  t_list_int  *tmp;
  t_list_int  *new;
  int         min_dist;

  x = id;
  push_pop_id(house, x);
  tmp = house->dijkstra->rest;
  while (tmp)
  {
    if (house->dijkstra->adjacent_matrix[x][tmp->nb])
    {
      min_dist = find_min_list_int(house->dijkstra->dist[x]);
      if (house->dijkstra->dist[tmp->nb]->nb == -1)
      {
        if (min_dist == -1)
          house->dijkstra->dist[tmp->nb]->nb = 1;
        else
          house->dijkstra->dist[tmp->nb]->nb = min_dist + house->dijkstra->adjacent_matrix[x][tmp->nb];
        house->dijkstra->pred[tmp->nb]->nb = x;
      }
      else
      {
        new = LIST_NEW(t_list_int);
        new->nb = min_dist + house->dijkstra->adjacent_matrix[x][tmp->nb];
        LIST_PUSH_BACK(&house->dijkstra->dist[tmp->nb], new);
        new = LIST_NEW(t_list_int);
        new->nb = x;
        LIST_PUSH_BACK(&house->dijkstra->pred[tmp->nb], new);
      }
    }
    tmp = tmp->next;
  }
}

static int  find_min(t_anthill *house)
{
  t_list_int    *tmp;
  int           min;
  int           ret;

  tmp = house->dijkstra->rest;
  ret = -1;
  min = -1;
  while (tmp)
  {
    if (house->dijkstra->tab_rooms[tmp->nb]->type != ROOM_END)
    {
      if (house->dijkstra->dist[tmp->nb]->nb != -1 && min == -1)
      {
        min = house->dijkstra->dist[tmp->nb]->nb;
        ret = tmp->nb;
      }
      else if (house->dijkstra->dist[tmp->nb]->nb != -1 && house->dijkstra->dist[tmp->nb]->nb < min)
      {
        min = house->dijkstra->dist[tmp->nb]->nb;
        ret = tmp->nb;
      }
    }
    tmp = tmp->next;
  }
  return (ret);
}

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

static t_list_int   **get_road(t_anthill *house)
{
  t_list_int  **road;
  int         nb_road;
  int         id;
  int         x;
  int         i;
  int         i_room;
  int         nb_step;

  nb_road = LIST_COUNT(house->dijkstra->pred[house->nb_rooms - 1]);
  road = (t_list_int **)malloc(sizeof(t_list_int *) * (nb_road + 1));
  ft_bzero(road, sizeof(t_list_int *) * nb_road);
  road[nb_road] = NULL;
  i_room = 0;
  while (i_room < nb_road)
  {
    printf("i_room: %d\n", i_room);
    x = house->end->id;
    push_id(&road[i_room], x);
    nb_step = house->dijkstra->dist[house->nb_rooms - 1]->nb;
    printf("nb_step = %d\n", nb_step);
    remove_id(&house->dijkstra->dist[x], house->dijkstra->dist[x]->nb);
    i = 0;
    while (i < nb_step)
    {
      id = house->dijkstra->pred[x]->nb;
      printf("x = %d, id = %d\n", x, id);
      if (remove_id_all_list(house, house->dijkstra->pred, id))
        push_id(&road[i_room], id);
      x = id;
      i++;
    }
    printf("\n%s\n", "== Intermetiate ==");
    print_list("rest", house->dijkstra->rest);
    print_list("already", house->dijkstra->already);
    print_tab_list("dist", house->dijkstra->dist);
    print_tab_list("pred", house->dijkstra->pred);
    printf("%s\n", "== === ==");
    i_room++;
  }
  return (road);
}

t_list_int    **dijkstra_it(t_anthill *house)
{
  int     x;

  house->dijkstra->dist[house->start->id]->nb = 0;
  x = find_min(house);
  fill_it(house, x);
  while (house->dijkstra->already != NULL && (x = find_min(house)) != -1)
    fill_it(house, x);
  return (get_road(house));
}
