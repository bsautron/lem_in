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

static int remove_id_rest(t_anthill *house, int id)
{
  t_list_int    *tmp;
  t_list_int    *prev;

  tmp = house->dijkstra->rest;
  if (tmp->nb == id)
    house->dijkstra->rest = tmp->next;
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

static void push_id_already(t_anthill *house, int id)
{
  t_list_int    *new;

  new = LIST_NEW(t_list_int);
  new->nb = id;
  LIST_PUSH_FRONT(&house->dijkstra->already, new);
}

static void push_pop_id(t_anthill *house, int id)
{
  if (remove_id_rest(house, id))
    push_id_already(house, id);
}

static int  find_min_dist(t_list_int *list)
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
  // int         y;
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
      min_dist = find_min_dist(house->dijkstra->dist[x]);
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
        LIST_PUSH_FRONT(&house->dijkstra->dist[tmp->nb], new);
        new = LIST_NEW(t_list_int);
        new->nb = x;
        LIST_PUSH_FRONT(&house->dijkstra->pred[tmp->nb], new);
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
    printf("\t%2d, %2d\n", tmp->nb, house->dijkstra->dist[tmp->nb]->nb);
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
  printf("%s = %d\n", "ret(x)", ret);
  return (ret);
}

void    dijkstra_it(t_anthill *house)
{
  int     x;

  house->dijkstra->dist[house->start->id]->nb = 0;
  x = find_min(house);
  fill_it(house, x);
  print_list("rest", house->dijkstra->rest);
  print_list("already", house->dijkstra->already);
  print_tab_list("dist", house->dijkstra->dist);
  print_tab_list("pred", house->dijkstra->pred);
  printf("%s\n", "");
  while (house->dijkstra->already != NULL && (x = find_min(house)) != -1)
  {
    fill_it(house, x);
    print_list("rest", house->dijkstra->rest);
    print_list("already", house->dijkstra->already);
    print_tab_list("dist", house->dijkstra->dist);
    print_tab_list("pred", house->dijkstra->pred);
    printf("%s\n", "");
  }
}
