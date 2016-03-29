#include <lem_in.h>

int remove_id(t_list_int **list, int id)
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
