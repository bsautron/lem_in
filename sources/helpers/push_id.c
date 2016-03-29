#include <lem_in.h>

void push_id(t_list_int **list, int id)
{
  t_list_int    *new;

  new = LIST_NEW(t_list_int);
  new->nb = id;
  LIST_PUSH_FRONT(list, new);
}
