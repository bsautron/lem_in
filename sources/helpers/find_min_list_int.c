#include <lem_in.h>

int  find_min_list_int(t_list_int *list)
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
