#include <lem_in.h>

void print_list(char *name, t_list_int *list)
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
