#include <lem_in.h>

int remove_id(t_list_int **list, int id)
{
  t_list_int    *tmp;
  t_list_int    *prev;
  t_list_int	*less;
  int			ret;

	ret = 0;
  tmp = *list;
  if (tmp->nb == id)
    *list = tmp->next;
  prev = tmp;
  while (tmp)
  {
    if (tmp->nb == id)
    {
      prev->next = tmp->next;
      ret = 1;
    }
    prev = tmp;
    tmp = tmp->next;
  }
  if (*list == NULL)
  {
	  less = LIST_NEW(t_list_int);
	  less->nb = -1;
	  LIST_PUSH_FRONT(list, less);
  }
  return (ret);
}
